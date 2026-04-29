#include <ansi.h>
inherit ROOM;
void create()
{
     set("short","花径");
     set("long",@LONG
这是一条清幽的花径，两旁修竹姗姗，花径鹅卵石上生满
青苔，显得平素少有人行。花径通到三间石屋之前。屋前屋后
七八株苍松夭矫高挺，遮得四下里阴沉沉的。
LONG);
     set("exits", ([ /* sizeof() == 5 */
        "northwest"  : __DIR__"qishi",
         "northeast" : __DIR__"qintang",
         "east"      : __DIR__"huashi",
         "west"      : __DIR__"jiushi", 
         "south"     : __DIR__"yuedong",
         ]));
     setup();
     replace_program(ROOM);

}