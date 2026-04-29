//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "杭州香格");
	set("long", @LONG
	这是西湖边供游人租画舫,游艇到湖上游览的地方.虽然很大,但
招待的人却不多,大概因为许多人更愿意沿湖步行吧.但要去"三潭映月",
"平湖秋月"却是非乘船去不可的.在香格入口处,一位老板正笑眯眯地招呼
来人.他身边有一块牌子(sign),上面有字.西边不远处是著名的岳坟.
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_road2", 
	"west"  : __DIR__"h_yfen",
	 ]) );
	set("objects",([
	__DIR__"npc/boss" : 1,
	]));
	
	set("item_desc",([
	"sign" : "出租(rent)小艇,每人十两银子.\n",
	]));

        setup();
}

