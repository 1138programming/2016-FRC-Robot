# Fixing Non Fast Forward
### By Edward Pedemonte

When working on github code, you may sometimes encounter a non-fast forward error. If this error was encountered and you've already tried fetching and pulling, you may need to reset your code to the latest github version. To do this, follow this tutorial.

###### THIS WILL DELETE ALL OF YOUR CURRENT CHANGES. If you have changes you need to save, export them somewhere else for now, follow these instructions, and then go to the section on manually merging changes.

For each branch available in your eclipse project (By right clicking your project, going to Team -> Switch To), follow these directions:

1.  Right-click on your project and go to Team -> Fetch from Upstream. This will bring up a list of changes. Just click OK.
2.  Switch to the branch (e.g. master)
3.  Right-click on your project and go to Team -> Reset.... Open up Remote Tracking. Click on the branch you are on (make sure it starts with `origin`).
4.  Make sure that the reset type is set to Hard, and click reset.

If you have any changes in that branch, and you have exported it somewhere else for the time being, follow the next few steps:

1.  Open up the files without copies in Eclipse, and open up the files without changes with Notepad.
2.  This will sound tedious, but it will prevent errors when trying to merge: Go line by line and change the code in Eclipse with ONLY the changes that you have done. Try to keep the eclipse version as unchanged as possible, as there may be many changes in that version that have been done differently. Also try to keep the original format of the version on Eclipse.
