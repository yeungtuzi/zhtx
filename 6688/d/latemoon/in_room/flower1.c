#include <room.h>

inherit ROOM;

void create()
{
   set("short", "内厅穿堂");
        set("long", @LONG
通过『 垂花门 』便是往後院。垂花门为男女之门限，古来女
人就有「大门不出，二门不迈」的谚语，於是二门堪称为男女门限
。後院为庄内女弟子厢房，与湘园。东面一扇小门，为庄内更衣沐
浴的小花池。更是严禁外人胡乱闯入。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
     "north" :__DIR__"corridor7",
     "south" :__DIR__"flowerc",
     "east" :__DIR__"bathroom1",

]));
     create_door("north","垂花门","south", DOOR_CLOSED);
     create_door("east","小帘门","west", DOOR_CLOSED);

        setup();
        replace_program(ROOM);
}
