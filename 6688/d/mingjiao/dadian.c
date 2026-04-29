//room: /d/mingjiao/dadian.c
// by yeung

inherit ROOM;

void create()
{
        set("short","明教宝殿");
        set("long", @LONG
  这里是明教教主日常理事之所在，大殿中十分空旷，殿顶高悬八盏
金灯，两旁是精壮佩剑武士剑气森严逼人。正中设一宝座，前有一雕
花檀木案，宝座后立有一扇玉屏，屏中所画正是明教圣火图，烈焰直
逼日月。宝座上端坐一人，左右光明使者侍立两旁，正是明教青年教
主张无忌。
LONG
           );

        set("exits",([
            "south" : __DIR__"guangmingding",
            "north" : __DIR__"houhuayuan1",
        ]));
      

        set("objects",([
		"/adm/npc/zhangwuji":1,
        	"/class/mingjiao/yangxiao":1,
	        "/class/mingjiao/fanyao":1,
	]));

        
        setup();
}
