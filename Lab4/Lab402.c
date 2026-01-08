/*
Computer Programming for Computer Engineer - Lab 4.1
Deadline: 10/01/2026 23:55 น. ส่งส่ ได้ 0/15 ครั้ง
Problem
เมื่อมื่พอยน์เน์ตอร์ 1 ระดับ ถูกถู ประกาศใน main() แล้วฟังก์ชันย่อย่ ยจะเปลี่ยนการชี้ไปที่อื่นๆ ได้อย่าย่ งไร? และจะนำ ข้อมูลที่ชี้อยู่มยู่ าใช้งานในฟังก์ชันได้
อย่าย่ งไร?
Pre-code
Code
void go( int **p, int *z ) ;
int main() {
int *a, b = 10, c = 20 ;
go( &a, &b ) ;
printf( "%d %p %p", *a, a, &a ) ;
go( &a, &c ) ;
printf( "%d %p %p", *a, a, &a ) ;
return 0 ;
}

*/


