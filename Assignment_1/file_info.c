#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main() {
    char filename[256];
    struct stat fileStat;

    printf("Enter file name: ");        //Accept file name
    scanf("%255s", filename);

    if (stat(filename, &fileStat) == -1) {
        perror("Error getting file info");
        return 1;
    }

    //file info-
    printf("\nFile: %s\n", filename);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Inode: %ld\n", fileStat.st_ino);
    printf("Hard Links: %ld\n", fileStat.st_nlink);
    printf("Owner UID: %d\n", fileStat.st_uid);
    printf("Group GID: %d\n", fileStat.st_gid);

    //file type-
    if (S_ISREG(fileStat.st_mode)) printf("File Type: Regular File\n");
    else if (S_ISDIR(fileStat.st_mode)) printf("File Type: Directory\n");
    else if (S_ISLNK(fileStat.st_mode)) printf("File Type: Symbolic Link\n");
    else printf("File Type: Other\n");

    //file permissions-
    printf("Permissions: ");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    //last access/modify time-
    printf("Last Access: %s", ctime(&fileStat.st_atime));
    printf("Last Modify: %s", ctime(&fileStat.st_mtime));

    return 0;
}