REM  *****  BASIC  *****

Sub Main

End Sub



sub diaNormal

	Dim oDoc As Object
	Dim oSheet As Object
	Dim oCell As Object
	
	oDoc = ThisComponent
	oSheet = oDoc.Sheets.getByName("Sheet1")
	Camisa = oSheet.getCellRangeByName("B2")
	Cueca = oSheet.getCellRangeByName("D2")
	Meias = oSheet.getCellRangeByName("E2")
	Shorts = oSheet.getCellRangeByName("F2")
	
	
	Camisa.Value = Camisa.Value - 2
	Cueca.Value = Cueca.Value - 2
	Meias.Value = Meias.Value - 1
	Shorts.Value = Shorts.Value - -1

end sub

sub RESET

	Dim oDoc As Object
	Dim oSheet As Object
	Dim oCell As Object
	
	oDoc = ThisComponent
	oSheet = oDoc.Sheets.getByName("Sheet1")
	Camisa = oSheet.getCellRangeByName("B2")
	Jeans = oSheet.getCellRangeByName("C2")
	Cueca = oSheet.getCellRangeByName("D2")
	Meias = oSheet.getCellRangeByName("E2")
	Shorts = oSheet.getCellRangeByName("F2")
	SJeans = oSheet.getCellRangeByName("G2")
	Toalhas = oSheet.getCellRangeByName("H2")
	RC = oSheet.getCellRangeByName("I2")
	
	
	Camisa.Value = 12
	Jeans.Value = 2
	Cueca.Value = 12
	Meias.Value = 7
	Shorts.Value = 7
	SJeans.Value = 2
	Toalhas.Value = 2
	RC.Value = 2


end sub

sub diaFinal

	Dim oDoc As Object
	Dim oSheet As Object
	Dim oCell As Object
	
	oDoc = ThisComponent
	oSheet = oDoc.Sheets.getByName("Sheet1")
	Camisa = oSheet.getCellRangeByName("B2")
	Jeans = oSheet.getCellRangeByName("C2")
	Cueca = oSheet.getCellRangeByName("D2")
	Meias = oSheet.getCellRangeByName("E2")
	Toalhas = oSheet.getCellRangeByName("H2")
	RC = oSheet.getCellRangeByName("I2")
	bool = oSheet.getCellRangeByName("A8")
	
	
	Camisa.Value = Camisa.Value - 1
	Jeans.Value = Jeans.Value - 1
	Cueca.Value = Cueca.Value - 1
	Meias.Value = Meias.Value - 1
	Toalhas.Value = Toalhas.Value - 1
	
	if(bool.getString = "SIM") then
		RC.Value = RC.Value - 1
		bool.String = "NÃO"
	elseif(bool.getString = "NÃO") then
		RC.Value = RC.Value
		bool.String = "SIM"
	end if		

end sub