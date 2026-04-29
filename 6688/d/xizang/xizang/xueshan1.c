// /d/xizang/xueshan1.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里是由川入藏必经的大雪山,从这里往西,山势越行越高,气候也越来越
冷,你已经冻得有些发抖了,如果内功不好的话,最好买件皮衣御寒.
LONG
        );
        set("exits", ([
 "westup"    : __DIR__"xueshan2",
 "eastdown"  : __DIR__"xueshan0",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
