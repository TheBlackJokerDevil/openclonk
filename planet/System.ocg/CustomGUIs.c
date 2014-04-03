/*
	This file contains functions that are used for layouting custom menus.
*/

global func GuiAction_Call(proplist target, string function, value)
{
	return [GUI_Call, target, function, value];
}

global func GuiAction_SetTag(string tag, int subwindow, object target)
{
	return [GUI_SetTag, tag, subwindow, target];
}

global func Gui_AddMargin(proplist submenu, int marginX, int marginY)
{
	submenu.X = submenu.X ?? [0, 0];
	submenu.Y = submenu.Y ?? [0, 0];
	submenu.Wdt = submenu.Wdt ?? [1000, 0];
	submenu.Hgt = submenu.Hgt ?? [1000, 0];
	
	// safety, the coordinates could be a single value
	if (GetType(submenu.X) != C4V_Array) submenu.X = [submenu.X, 0];
	if (GetType(submenu.Y) != C4V_Array) submenu.Y = [submenu.Y, 0];
	if (GetType(submenu.Wdt) != C4V_Array) submenu.Wdt = [submenu.Wdt, 0];
	if (GetType(submenu.Hgt) != C4V_Array) submenu.Hgt = [submenu.Hgt, 0];
	
	submenu.X[1] += marginX;
	submenu.Y[1] += marginY;
	submenu.Wdt[1] -= marginX;
	submenu.Hgt[1] -= marginY;
	return true;
}

global func Gui_AddCloseButton(proplist menu, proplist target, string callback, parameter)
{
	var close_button =
	{
		Priority = 0x0fffff,
		Left = "100%-2em", Top = "0%+0em",
		Right = "100%", Bottom = "0%+2em",
		Symbol = Icon_Cancel,
		BackgroundColor = {Std = 0, Hover = 0x50ffff00},
		OnMouseIn = GuiAction_SetTag("Hover"),
		OnMouseOut = GuiAction_SetTag("Std"),
		OnClick = GuiAction_Call(target, callback, parameter)
	};
	Gui_AddSubwindow(close_button, menu);
	return close_button;
}

global func Gui_UpdateText(string text, int menu, int submenu, object target)
{
	var update = {Text = text};
	CustomGuiUpdate(update, menu, submenu, target);
	return true;
}

// adds proplist /submenu/ as a new property to /menu/
global func Gui_AddSubwindow(proplist submenu, proplist menu)
{
	do
	{
		var uniqueID = Format("child%d", RandomX(10000, 0xffffff));
		if (menu[uniqueID] != nil) continue;
		menu[uniqueID] = submenu;
		return true;
	} while (true);
}

// converts an integer into a "em"-value string that can be used as a position for a GUI. The value will be divided by "factor" which is 10 by default
global func ToEmString(int value, int factor)
{
	factor = factor ?? 10;
	var sign = "";
	if (value >= 0) sign = "+";
	return Format("%s%d.%dem", sign, value / factor, Abs(value % factor));
}