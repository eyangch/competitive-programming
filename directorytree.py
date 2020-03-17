import os
totalfiles = 0
arr = []
for root, dirs, files in os.walk("."):
    if "directorytree.py" in files:
        files.remove("directorytree.py")
    if "README.md" in files:
        files.remove("README.md")
    for i in files:
        arr.append("[" + root + "/" + i + "](" + root + "/" + i + ")")
        totalfiles += 1
    if ".git" in dirs:
        dirs.remove(".git")
print("### Total Files: " + str(totalfiles))
for i in arr:
    print(i + "\\")
