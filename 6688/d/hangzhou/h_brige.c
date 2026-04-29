//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "钱塘江石桥");
	set("long", @LONG
	往北过了大桥是杭州城中，往南过了大桥是杭州城南门。桥身宽阔，
结实，桥上人来人往，车水马龙，很有几分热闹。桥下潮声震天，撼人心魄。
LONG
        );
        set("exits", ([
	"north" : __DIR__"h_cross",
	"south" : __DIR__"sgate",
	 ]) );
	
        setup();
}

