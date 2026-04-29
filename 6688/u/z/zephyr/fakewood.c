//杨树


inherit ITEM;

void create()
{
	set_name("杨树", ({ "yang wood"}));
	set_weight(100000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "棵");
		set("long",@LONG
一棵碗口粗的杨树，枝繁叶茂，但是不知道被谁
给砍倒了，真是作孽啊！
LONG
			);
		set("value", 0);
	}
	set("unpawnable",1);
	setup();
}
