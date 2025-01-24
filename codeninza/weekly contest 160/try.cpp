#include <iostream>

// Function to move disks
void moveDisks(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        std::cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << std::endl;
        return;
    }
    moveDisks(n - 1, from_rod, aux_rod, to_rod);
    std::cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << std::endl;
    moveDisks(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n = 3; // Number of disks
    std::cout << "Solution for Tower of Hanoi with " << n << " disks:" << std::endl;
    moveDisks(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}