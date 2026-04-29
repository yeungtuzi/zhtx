//杨树


inherit ITEM;

void create()
{
	set_name("杨树", ({ "yang shu"}));
	set_weight(120000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "棵");
		set("long",@LONG
一棵碗口粗的杨树，一打眼看上去没什么特殊，仔细端详杨树的
断口，你发现年轮密密麻麻，数都数不清楚，这棵不是很粗的样
子，没想到竟然已经生长了那么久了！
LONG
			);
		set("value", 0);
	}
	set("unpawnable",1);
	setup();
}
