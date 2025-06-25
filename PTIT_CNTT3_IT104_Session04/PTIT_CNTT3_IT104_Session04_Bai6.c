#include <stdio.h>
#include <string.h>

// B1: Khởi tạo cấu trúc 'Student' với 3 thuộc tính: id, name, age
struct Student {
    int id;
    char name[55];
    int age;
};

int main () {
    // B2: Khai báo mảng 'studentList' lưu thông tin của 5 sinh viên
    struct Student studentList[5];

    // B3: Sử dụng vòng lặp để nhập thông tin cho từng sinh viên
    for (int i = 0; i < 5; i++) {
        printf("Nhap thong tin sinh vien so %d:\n", i + 1);
        printf("id: ");
        scanf("%d", &studentList[i].id);
        printf("name: ");
        scanf("%s", studentList[i].name);
        printf("age: ");
        scanf("%d", &studentList[i].age);
    }

    int targetID;
    // B4: Khai báo biến 'targetID' để lưu ID cần tìm
    printf("Nhap id sinh vien can tim: ");
    scanf("%d", &targetID);

    int foundIndex = -1;
    // B5: Khai báo biến 'foundIndex' để lưu chỉ số nếu tìm thấy

    for (int i = 0; i < 5; i++) {
        // B6: Duyệt qua mảng để tìm sinh viên có ID bằng 'targetID'
        if (studentList[i].id == targetID) {
            foundIndex = i; // Gán chỉ số tìm thấy vào 'foundIndex'
            break;
        }
    }

    // B7: Kiểm tra kết quả và in thông tin sinh viên nếu tìm thấy
    if (foundIndex != -1) {
        printf("id: %d, name: %s, age: %d\n",
               studentList[foundIndex].id,
               studentList[foundIndex].name,
               studentList[foundIndex].age);
    } else {
        printf("Sinh vien khong ton tai");
    }

    return 0;
}

