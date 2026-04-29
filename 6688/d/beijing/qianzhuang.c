// Room: qianzhuang.c
#include <ansi.h>
inherit BANK;

void create()
{
	set("short", CYN"顺升钱庄"NOR);
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。
它发行的银票信誉非常好，通行全国。不管你走到哪里，在任何一个本
庄分店都可以任意存取。墙上挂着一个牌子(paizi)。
LONG
	);

	set("item_desc", ([
	"paizi": @TEXT
存取自由，通存通取!	
目前我们提供的服务有：

convert     兑换钱币。
deposit     存钱。你最多可存十万两银子。
withdraw    提款。
balance     查询自己目前的存款数。

TEXT
	]));
	set("exits", ([
		"north" : __DIR__"changjie1",
	]));

	set("objects", ([
//		__DIR__"npc/qianlaob" : 1
	]));

	setup();
	
}

