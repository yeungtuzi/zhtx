//gebitan1.c

inherit ROOM;

void create()
{
        set("short", "戈壁滩");
	set("long", @LONG
	离开小镇，眼前是一望无际的戈壁滩，没有路标，也没
有一个行人，天显得很高，远山披雪，苍鹰翱翔，好一派不同于中
土的异域风光。不远处，几只白骨散落地上，似乎是牦牛的尸骨，
走在这茫茫戈壁之上，你似乎迷路了。
LONG
	);
 	set("exits",([
		      "west" : __DIR__"gebitan2",	
		      "north" : __DIR__"gebitan1",
                      "south" : __DIR__"xiaozhen",  				
	]));
	set("objects",([
			"/d/mingjiao/obj/stone":1,	
	]));
	setup();
	replace_program(ROOM);
}
