// Room: /d/wizard/wizard_room1.c
//dai 97 .12.3
inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "巫师交谊大厅");
	set("long", @LONG

一进大厅视，野马上开阔起来。四十九根要五人合抱才能抱住的汉白玉柱,
支架起整个大厅。厅顶上安装了一百盏水晶灯,照的大厅金碧辉煌，甚是夺
目。大厅中间放置了一张供五十人开会用的会议桌(desk),左上角放置了一
百台电脑(computer),几十个巫师正在作新的门派，寂微手中拿着一根皮鞭
正在监工呢！右上角是讨论区，石头，玩家,巡洋舰等几个巫师正座在沙发
(sofa)上,讨论着以后发展动向的问题.左下方是休息室燕十三正翻看着USA
playboy magazine 不时发出一阵淫笑.龙五正在玩着gameboy口水流的满身
都是，他也一点也没察觉到。太奇头上插着自己写的“我在思考人类的最深
奥的问题”的小旗，已神游太虚了。云龙坐在自己的笔记本电脑前,不时翻看
着由世界各地漂亮的美眉寄来得征婚玉照,手上的极品云烟烧到手上也没觉察
到。天狼和点点 正听着walkman样子很是写意。右下脚堆放着世界各地的人民
送来自己民族的图腾。

LONG );

	set("exits", ([ /* sizeof() == 1 */
  	"yueyang" : "/d/yue/yang/guangchang",
        "choyin" : "/d/choyin/hotel1",
 	"canyon" : "/d/canyon/camp1",
        "cloud" : "/d/cloud/nwroad3",
        "death" : "/d/death/gate",
	"gaibang" : "/d/gaibang/inhole",
        "green" : "/d/green/path2",
        "guanwai" : "/d/guanwai/chanhouse",
  	"hangzhou" : "/d/hangzhou/chuanpu",
	"heimuya" : "/d/heimuya/cdd",
	"huashan" : "/d/huashan/shufang",
  	"jingcheng" : "/d/jingcheng/tamgch",
 	"latemoon" : "/d/latemoon/latemoon1",
	"maintown" : "/d/maintown/mt_road4",
	"mingjiao" : "/d/mingjiao/dadian",
	"olapine" : "/d/oldpine/clearing",
  	"quanzhou" : "/d/quanzhou/houyuan",
	"resort" : "/d/resort/back_yard",
	"shaolin" : "/d/shaolin/guangchang2",
	"snow" : "/d/snow/inn",
 	"suzhou" : "/d/suzhou/shizx",
	"taishan" : "/d/taishan/fengchan",
	"taoguan" : "/d/taoguan/da_dian",
	"taohua" : "/d/taohua/houhuayuan",
	"tieflag" : "/d/tieflag/goldroom",
	"waterfog" : "/d/waterfog/entrance",
	"wudang" : "/d/wudang/sanqingdian",
	"xingxiu" : "/d/xingxiu/xxh1",
	"xkisland" : "/d/xkisland/cave1",
	"xueshan" : "/d/xueshan/house",
        "east" : "__DIR__"wizard_room",
        ]));
        set("item_desc", ([
                "desk": "由一棵万年的白檀树经人间的能工巧匠精心雕刻而成。\n"
                        "由于是为巫师们制作，雕刻的很是精细桌四周雕刻着九条龙，势似欲飞。\n",
                "cmoputer": "处理器：采用MMXtm技术的intel pentium@III366MHZ\n"
                       "芯片组：intel 660lx 内存：64M SDRAM 硬盘：6.4G\n"
                       "显示器：22寸 遥控 madem:67.2Kbps 声卡 3D音效\n"
                       "显示卡：3D图形加速 光驱：22倍速 美国boss音箱 人体工学键盘\n"
                       "有dai 云龙大师设计并由XO-team跨国集团总公司制造\n"
                "sofa" : "意大利产的真皮沙发，采用的是极其珍贵的北极学狐皮\n"
                         "全手工制做，全世界共有五十个这样的沙发，这就拥有了四十个\n"
        ]) );

	set("valid_startroom", 1);
	set("no_fight", "1");
	set("no_clean_up", 0);
	setup();

	call_other("/obj/board/wizard_j", "???");
}

void init()
{
    object me;
    me=this_player();

    if ( !wizardp( me ) )
    {
	if( wizhood( me ) == "(immortal)" ) return;
        me->move("/d/wizard/guest_room");
        message_vision(YEL"\n\n\n一个沉雷般的声音从上面传来：你怎么敢擅闯神仙的世界？？？！！\n\n\n"NOR, me );
        tell_object( me, "\n\n回去吧！有bug就去报告。:) \n\n");
        return;
    }
}
