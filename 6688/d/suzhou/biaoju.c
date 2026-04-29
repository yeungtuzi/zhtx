// Room: /d/suzhou/biaoju.c
// by dwolf
//97.11.4 
//modified by tlang
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"威远镖局"NOR);
	set("long", @LONG
	你来到一座结构宏伟的建筑前，左右石坛上各插着一根两丈多高的旗杆，杆
上青旗飘扬。右首旗子用金线绣着一头张牙舞爪的飞龙，龙四周祥云缭绕。左首旗子
上写着“威远镖局”四个金黄大字，银钩铁划，刚劲非凡。入口处排着两条长凳，一
位镖头和几名趟子手坐着把守。
LONG
	);

	set("exits", ([
		"south" : __DIR__"wroad3",
		"north" : __DIR__"lwchang",
//		"northwest" : __DIR__"qxku",
	]));

	set("objects", ([
		__DIR__"npc/biaotou2" : 1,
		__DIR__"npc/fighter2" : 2,
	]));
	set("valid_startroom",1);

	setup();
	"/obj/board/biaoju_b"->foo();
}

