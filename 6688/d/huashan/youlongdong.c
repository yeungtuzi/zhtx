//youlongdong.c  犹龙洞
//by emote

inherit ROOM;

void create()
{
	set("short","犹龙洞");
	set("long",
@LONG
这里就是山上的居民们供奉李老君的地方，因为感谢老君给他们带来了这
样一条路，所以人们年年祭祀，岁岁供奉，不敢有所亵渎。这里有一尊李老君
的塑像，塑像慈眉善目，老君正捻须微笑。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"out": __DIR__"laojungou",
		]));
	 
        set("sleep_room", 1);
        set("no_faint",1);
        set("family","华山派剑宗");
        set("no_fight", 1);

	setup();
}
