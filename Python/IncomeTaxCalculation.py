slab22_23OldRegime = {250000 : (0, 0, 0),
                      300000 : (5, 0, 0),
                      500000 : (5, 5, 0),
                      1000000 : (20, 20, 20)
                      } # income slab: (<60, <80, >80)

slab22_23NewRegime = {250000 : (0, 0),
                      300000 : (5, 0),
                      500000 : (5, 5),
                      600000 : (10, 5),
                      750000 : (10, 10),
                      900000 : (15, 10),
                      1000000 : (15, 15),
                      1200000 : (20, 15)
                      } # income slab : (FY 22-23, FY 23-24)


income, age = list(map(int, input("\t\tFORMAT\nincome\tage\n").split()))
print("Old tax Regime\tNew Tax regime\n\t\t{FY 22-23\tFY 23-24}")

if (age <= 60):
    age = 0
elif (age <= 80):
    age = 1
else:
    age = 2

flag = 0
for i in slab22_23OldRegime:
    if income <= i:
        flag = 1
        taxpercentage = slab22_23OldRegime[i][age]
        print(income * taxpercentage / 100, end = "\t\t")
        break
if (flag == 0):
    taxpercentage = 30
    print(income * taxpercentage / 100, end = "\t\t")

flag = 0
for i in slab22_23NewRegime:
    if (income <= i):
        flag = 1
        taxpercentage = slab22_23NewRegime[i]
        print(income * taxpercentage[0] / 100, "\t", income * taxpercentage[1] / 100)
        break
if (flag == 0):
    taxpercentage = [30, 30]
    print(income * taxpercentage[0] / 100, "\t", income * taxpercentage[1] / 100)
