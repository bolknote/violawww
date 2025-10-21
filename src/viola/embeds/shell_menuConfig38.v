
.	{Target parent}		{target(tweak(target(), "get(\"parent\");"));}
.	{Clone target}		{shell.top.tools("cloneTarget");}
.	{Info target}		{tweak(target(), "info();");}
.	{Save target}		{tweak(target(), "save();");}
.	{}
.	{Create object}		{op_create("visible", 1);}
.	{}
.	{Vicon}			{vicon("visible", 1);}
.	{save dump}		{saveAs("foo");}
.	{save command text}	{shell.in.tf("saveText");}
.	{load command text}	{shell.in.tf("loadText");}
.	{Quit}			{quit();}
