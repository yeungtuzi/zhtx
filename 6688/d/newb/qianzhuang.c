///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit BANK;

void create()
{
        set("short", HIM"相记钱庄"NOR);
        set("long", @LONG
这是一家老字号的钱庄在新村的分号，相老板是山西人，这家钱庄
从他的爷爷的爷爷的爷爷的爷爷那辈开始办起，一直传到他手里，声誉
非常好，在全国各地都有分店。它发行的银票通行全国。钱庄的门口挂
有一块牌子(paizi)。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"qsroad2",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/banker" : 1,
]));
        set("item_desc", ([
        "paizi" : "本庄可换钱，存钱，取钱，包你满意.\n
                   deposit <数量> <货币种类>\n
                   withdraw <数量> (unit: coin)\n
                   balance\n
                   convert <数量> <货币种类> to <货币种类>\n  ",
]));
                set("no_fight",1);

        setup();
}

