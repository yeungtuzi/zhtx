//老君沟
//
inherit ROOM;
void create()
{
	set("short","老君沟");
	set("long",
@LONG
出了仙人桥，又是一段陡路。传说这条两尺来宽的小路，是当年太上老君
以青牛拉犁，开出来的一条沟，于是就叫做“老君犁沟”了。如今我们看到卧
牛台上的那个“卧牛石”，就是当年老君的青牛，传说青牛在犁完犁沟后，看
到华山景色壮丽秀美，便化为石牛，永远地留在了华山之上。 旁边有个“犹龙
洞”，就是取孔子赞叹老子“岂犹龙乎”之意，把老君供奉起来，逢年过节，
来到洞内祭祀老君。

LONG);
         set("exits", ([ /* sizeof() == 2 */
		"westdown"  : __DIR__"xianrenqiao",
		"northup": __DIR__"yuntai",
                "northeastup": __DIR__"bieyuan",
		"enter"  : __DIR__"youlongdong",
		"east"   : __DIR__"chapeng",
		]));
	set("outdoors","huashan");	 
	setup();
	replace_program(ROOM);
}

