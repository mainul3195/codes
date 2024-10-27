import pyautogui
import random
import time

# List of messages to send
messages = [
    "Hello",
    "hi",
    "how are you",
    "I am fine",
    "Thank you",
    "You are welcome",
    "what are you doing",
    "I am doing well",
    "I am happy",
    "I am sad",
    "I am angry",
    "I am frustrated",
    "I am frustrated",
    "ki lav beche tehke?",
    "ekdin to morei zabo",
    "tai naki?",
    "ei bebohar?",
    "Thik ase",
    "dekhe nilam",
    "okke",
    "ok",
    "okk",
    "okkk",
    "okkkk",
    "okkkkk",
    "okkkkkk",
    "okkkkkkk",
    "okkkkkkkk",
    "okkkkkkkkk",
    "okkkkkkkkkk",
    "okkkkkkkkkkk",
    "okkkkkkkkkkkk",
    "okkkkkkkkkkkkk",
    "okkkkkkkkkkkkkk",
    "okkkkkkkkkkkkkkk",
    "okkkkkkkkkkkkkkkk",
    "okkkkkkkkkkkkkkkkk",
    "okkkkkkkkkkkkkkkkkk",
    "okkkkkkkkkkkkkkkkkkk",
    "okkkkkkkkkkkkkkkkkkkk",
    "okkkkkkkkkkkkkkkkkkkkk",
    "okkkkkkkkkkkkkkkkkkkkkk",
    "okkkkkkkkkkkkkkkkkkkkkkk"
]

# Number of messages to send
num_messages = 5000

# Interval between messages in seconds
interval = .001  # 200 milliseconds

# Wait for a few seconds to switch to the chat window
print("You have 5 seconds to switch to the chat window...")
time.sleep(5)
count = 1
for _ in range(num_messages):
    # message = random.choice(messages)
    message = "ok"
    count += 1
    pyautogui.typewrite(message)
    pyautogui.press('enter')  # Simulates pressing the 'Enter' key to send the message
    time.sleep(interval)  # Wait for the specified interval
