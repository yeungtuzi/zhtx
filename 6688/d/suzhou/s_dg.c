// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

string look_sign(object me);

/*string *npcs=({
	"s_ake",
	"s_ser",
	"s_zrou",
	"s_srui",
	"s_gzu",
	"s_fyi",
});	
*/
void create()
{
//	int i=random(sizeof(npcs));
	set("short", RED"赌馆"NOR);
	set("long", @LONG
	     你现在正站在赌场里，只见一大群人围着桌子大喊大叫，正中
间的人两眼贼兮兮的，旁边站着一位漂亮的女子。靠近门口的地方有一块乌木
雕成的招牌(sign)。
LONG
);
	set("exits",([
	"south" : __DIR__"s_yhx",
	]));

	set("objects",([
	"/adm/npc/s_xbao" : 1,
//	__DIR__"npc/"+npcs[i] : 1,
	__DIR__"npc/s_ser" : 1,
	__DIR__"npc/s_srui" : 1,
	__DIR__"npc/s_mjp":1,
	__DIR__"npc/s_ake" : 1,
//	__DIR__"npc/s_zrou":1,
//	__DIR__"npc/s_gzu":1,
//	__DIR__"npc/s_fyi":1,
	]));

	set("item_desc",([
	"sign" : (: look_sign :),
	]));

	setup();
}

string look_sign(object me)
{
	return "想赌的就把钱拿来，多少不限。\n";
}
