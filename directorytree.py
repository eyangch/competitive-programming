import os
arr = []
for root, dirs, files in os.walk("."):
    dirs.sort()
    files.sort()
    if root != ".":
        for i in files:
            arr.append("[" + root + "/" + i + "](" + root + "/" + i + ")")
    if ".git" in dirs:
        dirs.remove(".git")

rread = open("README.md")
storelines = []
for line in rread:
    if len(line) >= 16 and line[:16] == "### Total Files:":
        break
    storelines.append(line)
rread.close()

rwrite = open("README.md", mode="w")
for line in storelines:
    rwrite.write(line)

rwrite.write("### Total Files: " + str(len(arr)) + "\n")
for i in arr[:-1]:
    rwrite.write(i + "\\\n")
rwrite.write(arr[len(arr) - 1] + "\n")

rwrite.close()
