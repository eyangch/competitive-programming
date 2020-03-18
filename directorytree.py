import os
arr = []
for root, dirs, files in os.walk("."):
    dirs.sort()
    files.sort()
    if "directorytree.py" in files:
        files.remove("directorytree.py")
    if "README.md" in files:
        files.remove("README.md")
    for i in files:
        arr.append("[" + root + "/" + i + "](" + root + "/" + i + ")")
    if ".git" in dirs:
        dirs.remove(".git")
print("### Total Files: " + str(len(arr)))
for i in arr:
    print(i + "\\")
