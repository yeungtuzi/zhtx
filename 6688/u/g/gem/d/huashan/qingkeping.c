//青柯坪
//
inherit ROOM;
void create()
{
	set("short","青柯坪");
	set("long",
@LONG
青柯坪是一块很大的山间盆地，自此起，上山的路都是在山石上凿出来的。
其东侧有一块大石头，上刻“回心石”，这就是告诉上山的人：以后的路途凶
险，体力不济和胆小的人，到这里就可以回去了。远远的能看见一个小亭子，
就是传说中宋太祖赵匡胤和陈抟老祖下棋赌华山的赌棋亭。结果因为陈抟赢了
这盘棋，所以从此，华山的土地就不要缴纳钱粮了。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"northeast"  : __DIR__"xiaolu3",
		"southup": __DIR__"qianchizhuang",
		]));
        set("objects", ([
                CLASS_D("huashan") + "/shi" : 1
        ]));

	set("outdoors","huashan");	 
	setup();
	replace_program(ROOM);
}

