#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(BLK"手谕"NOR,({"letter"}));
    set_weight(100);
    set("unit","道");
    set("material","silk");
    set("long",@LONG
这道手谕加了火漆封印，防止人私自揭开了看，但是你怕什么(tear)？
LONG);
}

void init()
{
	add_action("do_tear", "tear");
}

int do_tear(string arg)
{
	if (arg != "letter" && arg != "手谕")
		return notify_fail("你要撕什么？\n");

	message_vision("$N把手谕撕开了。\n", this_player());
    	set("long", @LONG
这道手谕加了火漆封印，但是已经被人撕开了，上面写着：
    反贼赫连铁树拥兵自重，早有忤逆之心，丐帮既灭，你等二十人由傀名厍答
带领，持朕令牌号令铁鹞军，诛杀反贼赫连铁树，一品堂中若有不服者，一律杀
无赦！
LONG);

	return 1;
}
