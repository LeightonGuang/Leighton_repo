class students:
    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        self.pay = pay
        self.email = first + '.' + last + '@windermereschool.co.uk'

    def fullname(self):
        return '{} {}'.format(self.first, self.last)

    def info(self):
        print ('student is ' + self.fullname() + ' and pays ' + self.pay + ' and email is ' + self.email)


student_1 = students('Leighton', 'Guang', '10000')
student_2 = students('Kei', 'Ito', '20000')

#print ('student 1 is ' + student_1.fullname() + ' and pays ' + student_1.pay + ' and email is ' + student_1.email)
#print ('student 2 is ' + student_2.fullname() + ' and pays ' + student_2.pay + ' and email is ' + student_2.email)

students.info(student_1)
students.info(student_2)
