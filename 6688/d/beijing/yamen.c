// /d/beijing/yamen.c

inherit ROOM;

void create()
{
        set("short", "北平府衙");
        set("long", @LONG
    这里是北平城的衙门，两扇大门紧紧关闭着。大门上的牌匾上刻着几
个大字：北平府衙，门前有一个大鼓。北平府尹当中而做，十几名衙役
分居两旁，各自举着肃静、回避的牌匾。有不少人出出进进，络绎不绝。
LONG
        );

        set("exits", ([
                "south" : "/d/beijing/xisi2",
        ]));

        set("objects", ([
                "/d/beijing/npc/fuyin" : 1,
        ]));

        setup();
        replace_program(ROOM);
}


