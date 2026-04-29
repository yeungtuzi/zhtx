// valley_entrance.c
// by meteoric
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","山谷");
        set("long",@LONG
谷外冰天雪地，而谷内气温越来越暧，竟似已变得象是春天到来，
山谷中豁然开朗，群峰合抱间，竟是一片绿色。
LONG );

        set("objects",([
        	]));
        set("exits",  ([
        	"south":"/d/moyu/xueyuan/sankou",
        	"north":__DIR__"groad1",
        	]));
        set("blocks", ([
        	"north":"wolf king"
        	]));
        setup();
}