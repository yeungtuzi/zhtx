// cangjingge.c 藏经阁
// by Masterall
inherit ROOM;
void create()
{set("short", "藏经阁"); 
set("long", @LONG
    这里是藏经阁，靠墙是一排书架，摆满了各门各派的武功典籍。看来司空晓风近年
来没少费心思收集这些秘笈。每一本秘笈的后面必然都是一场腥风血雨的武林浩劫。
LONG
);
set("exits", ([
                "southdown" : __DIR__"xilang",
                "down" : __DIR__"cangjing2",
        ]));
set("objects", ([
//               "/d/qingcheng/obj/qforce" : 1,
               "/d/qingcheng/obj/zhang" : 1,
//               "/d/qingcheng/obj/pine-sword" : 1,
               "/d/qingcheng/obj/steps" : 1,
//               "/d/qingcheng/obj/sword" : 1,
               "/d/qingcheng/obj/force" : 1,
//               "/d/qingcheng/obj/qforce" : 1,
               "/d/resort/obj/book1":1,
               "/d/resort/obj/book2":1,
               "/d/resort/obj/book3":1,
               "/d/resort/obj/book4":1,
               "/d/resort/obj/book5":1,
               "/d/resort/obj/book6":1,
        ]));
setup();
//replace_program(ROOM);
}
