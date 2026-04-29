inherit ROOM;

void create()
{
        set("short", "元帅府");
        set("long", @LONG
        这里就是元帅府了，正堂中有一块巍峨的牌匾上面写着
“公正清廉”四个镶金大字，房间极大，两做巨型房住耸立在两旁
，远远看去甚是雄伟壮观，元帅本人当中而做。
LONG
        );

         set("no_fight",1);
        set("no_poison",1);
        set("no_magic",1);  
        set("no_death",1);
        set("exits", ([
                "east" : "/d/jingcheng/wumen",
        ]));

        set("objects", ([
//                  "/quest/killer/yuanshuai" : 1,
                  "/quest/killer/yuan" : 1,
//加入了几种大内密宝，以及玄机箱子 by masterall
        ]));

        setup();
        replace_program(ROOM);
}



