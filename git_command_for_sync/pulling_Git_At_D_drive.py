import os

d_dir = "/mnt/d/morseChat/"

current_path = os.popen("pwd").read()

os.system("cd /mnt/d/")

if os.popen("ls /mnt/d/ | grep morseChat | wc -l").read()[:-1] == "0":
    os.system("git -C /mnt/d clone https://github.com/ineiw/morseChat.git")
commandLine = "git stash && git -C /mnt/d/morseChat pull origin ineiw && git stash pop"
commandLine += "cd " + current_path 

os.system(commandLine)
