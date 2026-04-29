#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "监狱");
	set("long", @LONG
    这是专门用来关押违规者的牢房!你甭想逃出去!!
这里昏暗无光,借着那从破裂的天花板的缝隙里透下来
的微弱的光,你可以看到墙上(wall)刻有几个字。

LONG
	);


	set("valid_startroom",1);
	set("item_desc", ([
                "wall" : BLK "众怒难犯！\n\n" NOR,
                ]) );
	setup();

}

void init()
{       
	object ob = this_player();

	if( (int)ob->query_condition("bonze_jail") <= 0 )
	{
		message("vision",
			HIY "只听牢房铁门匡地一响，一个昏昏沉沉的家伙被扔了进来！\n\n" NOR, 
			environment(ob), ob);

		tell_object(ob, "狱卒嘿嘿地笑着：今儿个你可落在我手里了...！\n");

                ob->set("startroom", "/d/wizard/jianyu_wizard");
                ob->apply_condition("bonze_jail", 120);
	}
        add_action("do_goto","goto");
        add_action("do_summon","summon");
        add_action("do_chat","chat");
        add_action("do_chat","chat*");
        add_action("do_bid","bid");
        add_action("do_bid","new");
        add_action("do_bid","new*");
        add_action("do_chat","mp");
        add_action("do_pray","use");
        add_action("do_conjure","conjure");
        add_action("do_es","zh");
        add_action("do_es","zh*");
        add_action("do_rumor","rumor");
        add_action("do_rumor","rumor*");
        add_action("do_tell","tell");
        add_action("do_reply","reply");
        add_action("do_exercise","exercise");
        add_action("do_meditate","meditate");
        add_action("do_respirate","respirate");
        add_action("do_exert","exert");
        add_action("do_practice", "practice");
        add_action("do_study","study");
        add_action("do_cast","cast");
        add_action("do_fight","fight");
        add_action("do_hit","hit");
        add_action("do_kill","kill");
        add_action("do_steal","steal");
        add_action("do_pray","pray");
        add_action("do_scribe","scribe");
        add_action("do_burn","burn");
        add_action("do_attach","attach");
        add_action("do_vote","vote");
        add_action("do_music","music");
        add_action("do_music","music*");
        add_action("do_suicide","suicide");
        add_action("do_flyup","flyup");
        add_action("do_call","call");
        add_action("do_home","home");
        add_action("do_quit","quit");
}

        int do_bid(string arg)
{
                write( RED "你还是歇歇吧, 没人听得到的\n\n" NOR);
                return 1;
}

        int do_conjure(string arg)
{
                write( RED "在这儿你还想使神通!\n\n" NOR);
                return 1;
}

int do_chat(string arg)
{
                write( RED "坐牢还不老实!还想和外面通信儿啊？哈哈哈哈!!!\n\n" NOR);
                return 1;
}

int do_goto(string arg)
{
               write( RED "天子犯法，与庶民同罪,巫师也跑不了!\n" NOR );
               return 1;
}

int do_summon(string arg)
{
               write( RED "天子犯法，与庶民同罪,目前你就歇着吧!\n" NOR);
               return 1;
}

int do_es(string arg)
{
                write( RED "给老子安静一点!小心老子拿狗皮膏药贴你的嘴!!!\n\n" NOR);
                return 1;
}

int do_rumor(string arg)
{
                write( RED "哟!你坐牢还想造谣生事啊？闭嘴吧!你奶奶的!!\n\n" NOR);
                return 1;
}

int do_tell(string arg)
{
                write( RED "嘿!想和外面通气?给我老实呆这儿吧!!!\n\n" NOR);
                return 1;
}

int do_reply(string arg)
{
                write( RED "老子告诉你:你就给老子乖乖呆着!什么也甭做!\n\n" NOR);
                return 1;
}

int do_exercise(string arg)
{
                write( RED "练功干嘛？想走火入魔啊? 那样到省了老子的事!!\n\n" NOR);
                return 1;
}

int do_meditate(string arg)
{
                write( RED "是不是想冥思啊？小心变白痴喔!呜哈哈!\n\n" NOR);
                return 1;
}

int do_respirate(string arg)
{
                write( RED "想修行?坐牢了你还有屁资袼修行!!!???\n\n" NOR);
                return 1;
}
int do_exert(string arg)
{
                write( RED "想动真气? 当心老子挑断你奇经八脉\n\n" NOR);
                return 1;
}

int do_practice(string arg)
{
                write( RED "练功？老子把你手脚钉在木桩上!看你还动？\n\n" NOR);
                return 1;
}

int do_study(string arg)
{
                write( RED "读书?!老子挖了你的狗眼!!\n\n" NOR);
                return 1;
}

int do_cast(string arg)
{
                write( RED "念咒文?老子是鬼王!\n\n" NOR);
                return 1;
}

int do_fight(string arg)
{
                write( RED "手痒痒了?老子先打你一千棍!\n\n" NOR);
                return 1;
}

int do_hit(string arg)
{
                write( RED "老子警告你: 两手抱在头上!贴墙乖乖站着!别动!\n\n" NOR);
                return 1;
}

int do_kill(string arg)
{
                write( RED "到这你还想行凶?再关一年!\n\n" NOR);
                return 1;
}

int do_steal(string arg)
{
                write( RED "老子折断你的臭手!\n\n" NOR);
                return 1;
}

int do_pray(string arg)
{
                write( RED "哈哈!想飞?不怕从空中摔下来?\n\n" NOR);
                return 1;
}

int do_scribe(string arg)
{
                write( RED "哈哈!想画符?留着纸搽屁股吧!哈哈哈!\n\n" NOR);
                return 1;
}

int do_burn(string arg)
{
                write( RED "哈哈!你那草纸搽屁股都嫌脏了!\n\n" NOR);
                return 1;
}

int do_attach(string arg)
{
                write( RED "臭贼!到这还想害人?老子剁了你的狗爪子!!!\n\n" NOR);
                return 1;
}

int do_vote(string arg)
{
                write( RED "坐牢的人还想投票?羞不羞!!!\n\n" NOR);
                return 1;
}

int do_music(string arg)
{
                write( RED "在这还想唱歌? 老子撕破你的嘴!!!\n\n" NOR);
                return 1;
}

int do_suicide(string arg)
{
                write( RED "自杀? 你别弄脏了这儿的地!!!\n\n" NOR);
                return 1;
}
int do_flyup(string arg)
{
                write( RED "怎么，还想飞，也不看看你到了什么地方了!!!\n\n" NOR);
                return 1;
}
int do_call(string arg)
{
                write( RED "巫师犯罪一并处罚！\n\n" NOR);
                return 1;
}
int do_home(string arg)
{
                write( RED "巫师犯罪一并处罚！\n\n" NOR);
                return 1;
}
int do_quit(string arg)
{
                write( RED "你已经被彻底禁锢在这里了，老老实实别动！！\n\n" NOR);
                return 1;
}


