    #include <bits/stdc++.h>
    using namespace std;

    // #define long double

    const double EPS = 1e-8;
    const double INF = 1e18;
    const int MAXN = 10005;

    struct Point4D
    {
        double x, y, z, w;
        Point4D(double x = 0, double y = 0, double z = 0, double w = 0)
            : x(x), y(y), z(z), w(w) {}

        Point4D operator-(const Point4D &other) const
        {
            return Point4D(x - other.x, y - other.y, z - other.z, w - other.w);
        }

        Point4D operator+(const Point4D &other) const
        {
            return Point4D(x + other.x, y + other.y, z + other.z, w + other.w);
        }

        Point4D operator*(double scalar) const
        {
            return Point4D(x * scalar, y * scalar, z * scalar, w * scalar);
        }

        bool isValid() const
        {
            return isfinite(x) && isfinite(y) && isfinite(z) && isfinite(w);
        }
    };

    // Clean small values close to zero
    double cleanZero(double val)
    {
        return (abs(val) < EPS) ? 0.0 : val;
    }

    // Clean a point's coordinates
    Point4D cleanPoint(const Point4D &p)
    {
        return Point4D(cleanZero(p.x), cleanZero(p.y), cleanZero(p.z), cleanZero(p.w));
    }

    double dot(const Point4D &a, const Point4D &b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }

    double dist2(const Point4D &a, const Point4D &b)
    {
        Point4D diff = a - b;
        return max((double)0.0, dot(diff, diff)); // Ensure non-negative
    }

    struct Sphere
    {
        Point4D center;
        double radius2; // squared radius
        bool valid;

        Sphere() : radius2(0), valid(true) {}
        Sphere(const Point4D &c, double r2) : center(c), radius2(r2), valid(true)
        {
            if (!c.isValid() || !isfinite(r2) || r2 < -EPS)
            {
                valid = false;
            }
        }

        bool isValid() const
        {
            return valid && center.isValid() && isfinite(radius2) && radius2 >= -EPS;
        }
    };

    bool isInSphere(const Point4D &p, const Sphere &s)
    {
        if (!s.isValid() || !p.isValid())
            return false;
        return dist2(p, s.center) <= s.radius2 + EPS;
    }

    Sphere trivialSphere()
    {
        return Sphere(Point4D(), -1);
    }

    Sphere sphereFromPoint(const Point4D &p)
    {
        return Sphere(cleanPoint(p), 0);
    }

    Sphere sphereFromTwo(const Point4D &p1, const Point4D &p2)
    {
        Point4D center = cleanPoint((p1 + p2) * 0.5);
        double radius2 = dist2(p1, center);
        return Sphere(center, radius2);
    }

    // More numerically stable determinant calculation for small matrices
    vector<double> solveSystem(vector<vector<double>> &A, vector<double> &b)
    {
        int n = A.size();
        vector<double> x(n);

        // Scale equations for better numerical stability
        for (int i = 0; i < n; i++)
        {
            double maxVal = 0;
            for (int j = 0; j < n; j++)
            {
                maxVal = max(maxVal, abs(A[i][j]));
            }
            if (maxVal > EPS)
            {
                for (int j = 0; j < n; j++)
                {
                    A[i][j] /= maxVal;
                }
                b[i] /= maxVal;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int pivot = i;
            double maxPivot = abs(A[i][i]);

            // Find best pivot
            for (int j = i + 1; j < n; j++)
            {
                if (abs(A[j][i]) > maxPivot)
                {
                    maxPivot = abs(A[j][i]);
                    pivot = j;
                }
            }

            if (maxPivot < EPS)
                continue; // Skip if pivot is too small

            if (pivot != i)
            {
                swap(A[i], A[pivot]);
                swap(b[i], b[pivot]);
            }

            for (int j = i + 1; j < n; j++)
            {
                if (abs(A[j][i]) < EPS)
                    continue;
                double factor = A[j][i] / A[i][i];
                for (int k = i; k < n; k++)
                {
                    A[j][k] = cleanZero(A[j][k] - factor * A[i][k]);
                }
                b[j] = cleanZero(b[j] - factor * b[i]);
            }
        }

        // Back substitution
        for (int i = n - 1; i >= 0; i--)
        {
            if (abs(A[i][i]) < EPS)
            {
                x[i] = 0; // Set to 0 if equation is degenerate
                continue;
            }

            double sum = b[i];
            for (int j = i + 1; j < n; j++)
            {
                sum = cleanZero(sum - A[i][j] * x[j]);
            }
            x[i] = cleanZero(sum / A[i][i]);
        }

        return x;
    }

    Sphere sphereFromPoints(const vector<Point4D> &points)
    {
        int n = points.size();
        if (n == 0)
            return trivialSphere();
        if (n == 1)
            return sphereFromPoint(points[0]);
        if (n == 2)
            return sphereFromTwo(points[0], points[1]);

        int equations = n - 1;
        vector<vector<double>> A(equations, vector<double>(4));
        vector<double> b(equations);

        try
        {
            for (int i = 0; i < equations; i++)
            {
                Point4D p1 = points[i + 1];
                Point4D p0 = points[0];

                A[i][0] = 2 * (p1.x - p0.x);
                A[i][1] = 2 * (p1.y - p0.y);
                A[i][2] = 2 * (p1.z - p0.z);
                A[i][3] = 2 * (p1.w - p0.w);

                b[i] = cleanZero(dot(p1, p1) - dot(p0, p0));
            }

            vector<double> center_coords = solveSystem(A, b);
            Point4D center(center_coords[0], center_coords[1], center_coords[2], center_coords[3]);

            if (!center.isValid())
            {
                // Fallback to centroid if system solution is invalid
                Point4D sum;
                for (const auto &p : points)
                {
                    sum = sum + p;
                }
                center = cleanPoint(sum * (1.0 / n));
            }

            // Calculate maximum radius to all points
            double maxRadius2 = 0;
            for (const auto &p : points)
            {
                maxRadius2 = max(maxRadius2, dist2(center, p));
            }

            return Sphere(center, maxRadius2);
        }
        catch (...)
        {
            // Fallback to centroid in case of any numerical errors
            Point4D sum;
            for (const auto &p : points)
            {
                sum = sum + p;
            }
            Point4D center = cleanPoint(sum * (1.0 / n));
            double maxRadius2 = 0;
            for (const auto &p : points)
            {
                maxRadius2 = max(maxRadius2, dist2(center, p));
            }
            return Sphere(center, maxRadius2);
        }
    }

    int getRandom(int l, int r)
    {
        static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        return uniform_int_distribution<int>(l, r)(rng);
    }

    void customShuffle(vector<Point4D> &points)
    {
        int n = points.size();
        for (int i = n - 1; i > 0; i--)
        {
            int j = getRandom(0, i);
            swap(points[i], points[j]);
        }
    }

    Sphere welzl(vector<Point4D> &points, vector<Point4D> boundary, int n)
    {
        if (n == 0 || boundary.size() == 4)
        {
            return sphereFromPoints(boundary);
        }

        int idx = getRandom(0, n - 1);
        Point4D p = points[idx];
        swap(points[idx], points[n - 1]);

        Sphere s = welzl(points, boundary, n - 1);

        if (s.isValid() && isInSphere(p, s))
        {
            return s;
        }

        boundary.push_back(p);
        return welzl(points, boundary, n - 1);
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.precision(10);
        cout << fixed;

        int n;
        cin >> n;

        vector<Point4D> points(n);
        for (int i = 0; i < n; i++)
        {
            double x, y, z, w;
            cin >> x >> y >> z >> w;
            points[i] = Point4D(x, y, z, w);
        }

        customShuffle(points);

        Sphere minSphere = welzl(points, vector<Point4D>(), n);

        // Clean final output
        Point4D center = cleanPoint(minSphere.center);
        cout << center.x << " " << center.y << " " << center.z << " " << center.w << "\n";

        return 0;
    }