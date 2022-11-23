
// 31.What is the code segment that should be written to fill all the student data :
// a.for (cls = 0; cls < NumClasses; cls++)
// {
// 	for (stdcls = 0; stdcls < NumStudperClass; stdcls++)
// 	{
// 		Std[cls][stdcls] = FillEmployee();
// 	}
// }
// b.for (cls = 0; cls < NumClasses; cls++)
// {
// 	for (stdcls = 0; stdcls < NumStudperClass; stdcls++)
// 	{
// 		*(Std[cls] + stdcls) = FillEmployee();
// 	}
// }
// c.for (cls = 0; cls < NumClasses; cls++)
// {
// 	int x;
// 	x = sizeof(Std[cls]) / sizeof(struct Student);
// 	for (stdcls = 0; stdcls < x; stdcls++)
// 	{
// 		*(*(Std + cls) + stdcls) = FillEmployee();
// 	}
// }
// d.for (cls = 0; cls < NumClasses; cls++)
// {
// 	for (stdcls = 0; stdcls < NumStudperClass; stdcls++)
// 	{
// 		*(*(Std + cls) + stdcls) = FillEmployee();
// 	}
// }
