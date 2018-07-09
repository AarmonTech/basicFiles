
import xlrd


book=xlrd.open_workbook("students.xls")
sh=book.sheet_by_index(0)
a_value_from_sheet = str(sh.cell(0,1,).value)
print a_value_from_sheet
