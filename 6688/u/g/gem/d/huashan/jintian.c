//jintian.c 金天宫
//by emote

inherit ROOM;

void create()
{
	set("short","金天宫");
	set("long",
@LONG
金天宫是南峰上的主要建筑，也是华山上边最为宏伟壮观的建筑之一。这
里专门为供奉西方神帝--少昊（白帝）的，所以此建筑也称白帝祠。少昊号金
天氏，故名金天宫。金天宫大殿全为大片铁瓦，内塑有神像，院前大门边还建
有钟鼓楼。这里大片松林，枝高叶茂，中有古观庙宇，配上林间小道，景色非
常优美，有人曾做诗一首：“探幽凌绝境，谒帝陟层巅。赤日岩中出，清流树
梢悬。文窗陈俎豆，绣供错烽烟．．．”可见其非常之雄伟壮观。

LONG);
         set("exits", ([ /* sizeof() == 2 */
		"westup"  : __DIR__"songgui",
		"eastup"  : __DIR__"luoyan",
		"west":__DIR__"xiepo",
		"north":  __DIR__"zhandao2",
		]));
	 
	
	setup();
	
}
