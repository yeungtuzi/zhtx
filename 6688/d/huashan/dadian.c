//dadian.c 大殿
//By Emote
inherit ROOM;

void create()
{
	set("short","玉泉院大殿");
	set("long",
@LONG
由大院向北走，就是玉泉院的大殿了，这里原本是宋仁宗年间，道士贾
得升为其师父陈抟修建的祠堂，所以又叫希夷祠。玉泉院紧接华山峪口，大
殿傍山临水，泉流淙淙，山气霏霏，绿茵蓖日，峰峦当窗，幽竹傍岩，亭台
廊厢参差曲折，情趣映然。整个布局显的开朗豁达，清新明净。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"south"  : __DIR__"dayuan",
		
]));

        set("objects", ([ 
		__DIR__"npc/teller": 1,
	 ]) );

	setup();
	replace_program(ROOM);
}

