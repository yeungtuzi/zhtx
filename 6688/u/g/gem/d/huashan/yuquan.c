//yuquan.c 玉泉
//By Emote
inherit ROOM;

void create()
{
	set("short","玉泉");
	set("long",
@LONG
这里就是玉泉院之所以得名的著名的玉泉了。泉水晶莹如玉，与华山峰
顶的“玉井”相通，故称“玉泉”。唐朝有一位公主，一年的夏天，偕同侍女游
览华山，在莲花峰玉井打水洗头时，不慎将头上的玉簪坠落井里，很不高兴。
第二天公主下山后到这里休息，当她在泉水里梳洗时，却找到了在山上丢失
的那枚玉簪。这就证明该泉与玉井相通，因此就给这个泉起名“玉泉”。以后
又就地修筑了这个闻名的玉泉院。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"dayuan",
		
]));
        set("objects", ([ 
		__DIR__"npc/honour": 1,
	 ]) );



	set("outdoors","huashan");
	setup();
	
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"趴在玉泉的泉眼上用木杯舀了一杯水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口玉泉水，身上的每个毛孔都舒服极了。\n");
            me->receive_curing("sen",10);
            me->receive_curing("kee",10);
            me->receive_curing("gin",10);
        }
        else write("逮着不要钱的水就这么喝，至于吗?\n");

        return 1;
}

