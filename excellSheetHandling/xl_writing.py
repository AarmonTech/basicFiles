import xlwt

rb=xlwt.Workbook()

sheet=rb.add_sheet("1")

sheet.write(0,0,"roll")
sheet.write(0,1,"name")

rb.save("manish.xls")
