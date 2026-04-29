// /d/xixia/yamen.c

inherit ROOM;

void create()
{
        set("short", "西夏府衙");
        set("long", @LONG
    这里是西夏城的衙门，两扇大门紧紧关闭着。大门上的牌匾上刻着几
个大字：西夏府衙，门前有一个大鼓。西夏府尹当中而做，十几名衙役
分居两旁，各自举着肃静、回避的牌匾。有不少人出出进进，络绎不绝。
LONG
        );

        set("exits", ([
                "south" : "/d/xixia/northstreet4",
        ]));

        set("objects", ([
                "/d/xixia/npc/fuyin" : 1,
        ]));

        setup();
        replace_program(ROOM);
}


