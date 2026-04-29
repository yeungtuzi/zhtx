#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
string ask2();

void create()
{
        set_name("开阳", ({ "kai yang", "sevenf" }));
        set("nickname", HIC"天罡神武"NOR);
        set("long", 
"他是“中神通”王重阳的得意门徒，也是全真建教近百余年来屈指可数的高手\n"
"之一。他一家本来有兄弟七人，开阳排行老六。早年间兵荒马乱，兄弟失散，\n"
"在金兵血洗村庄时被当时武功天下第一的王重阳相救，收为弟子。数年后，全\n"
"真派势微，全真七子也每况愈下，在武林中的名气和地位大不如从前，但从未\n"
"有人敢小觑了全真派，那就是因为有他的存在。传说中他的心思极为敏锐，善\n"
"于从别人破绽中寻找机会，手中的一柄剑使开同归剑法以后，不给对方留任何\n"
"喘息防御躲避的机会。在武林中罕有敌手，但每次战后他自己也受伤不轻，那\n"
"是因为这种剑法过于霸道，很容易伤及自身。即便如此，他还是赢得了“天下\n"
"第一”的称号，成为当时全真派的新人掌教。传说中他还习得了大理的无上绝\n"
"学“六脉神剑”，但至始至终没有掌握运用的法门，让他抱憾终身。据说他也\n"
"是当年血战接天楼众多高手中的一个。\n");

        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 100);
        set("cor", 100);
        set("int", 100);
        set("spi", 100); 

        set("cps", 100); 
        set("per", 100);
        set("con", 100);
        set("kar", 100);
        set("bln", 100);

        set("kee", 10000);
        set("max_kee", 10000);
        set("gin", 5000);
        set("max_gin", 5000);
        set("sen", 5000);
        set("max_sen", 5000);
        set("force", 8000);
        set("max_force", 4000);
        set("force_factor", 300);
        set("atman",8000);
        set("max_atman", 4000);
        set("mana", 8000);
        set("max_mana", 4000);
        set("combat_exp", 20000000);
        set("score", 200000);

        set("apprentice_available", 3);
        set_skill("literate", 300);
        set_skill("force", 250);
        set_skill("yiyang-zhi", 250);
        set_skill("finger", 200);
        set_skill("sword", 250);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("xiantian-gong", 250);
        set_skill("xianyun",200);
        set_skill("fx-step",200);
        set_skill("tonggui-jian", 250);
        set_skill("quanzhen-jian", 250);
        set_skill("xuantie-sword", 220);
        set_skill("jiuyin-shengong", 220);
        set_skill("iron-cloth", 220);
        set_skill("taoism", 250);
        set_skill("yunu-jianfa", 200);


        map_skill("force", "xiantian-gong");
        map_skill("sword", "xuantie-sword");
        map_skill("dodge", "fx-step");
        map_skill("move", "xianyun");
        map_skill("parry", "quanzhen-jian");
        map_skill("iron-cloth", "jiuyin-shengong");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger", "yiyang-zhi");

        create_family("全真派", 2, "副掌门");
        set("title",HIB "全真派" NOR + HIG "副掌门" NOR);
        set_temp("apply/defense",1000);
        set_temp("apply/armor",1000);
        set_temp("apply/armor_vs_force",1000);   

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );        


        set("inquiry", ([
              "左右互搏": (: ask2 :),
                "懒猪": 
"哎~~~~~他是我以前的主人，可惜现在不知道哪里去了。\n",
                "道全": 
"那是天神啊!你问他干什么，记着，千万不要和他讨价还价！！！\n",
                "玩家": 
"千万别去见他，他是比白无常还可怕的家伙。\n"
        ]));
        setup();

        carry_object("/d/qiankun/obj/weapon/tiandunshenjian")->wield();

}


void init()
{
        object ob;
        ob = this_player();     
        ::init();
        if( interactive(ob) && !is_fighting() )
               {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        add_action("give_quest","quest");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if( random(10) < 2)
        {
                say("这位" + RANK_D->query_respect(ob)
                  +"好啊! 你知道懒猪跑哪里去了吗？....\n");
        }
        else
        if( random(10) > 8)
        {
                say("我一定要找个机会和一点红过过招,听说这家伙最近狂得很!\n");
        }
        else if (random(2) >0 )
        {
                command("bone " + ob->query("id"));
        }
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 我今天已经收了三个弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{  
      if( !ob->query("got_ling") ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"怎么跑到这侠客岛上来的，这里还不是你能来的地方！！");
                return;}
      if( (int)ob->query_skill("sword",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"剑术修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if (((string)ob->query("family/family_name")!="全真派")&&((string)ob->query("family/family_name")!="古墓派"))
        {
                command("say 你和全真古墓两派毫无干系，我不能收你。");
                return ;
        }

        if( (int)ob->query_skill("force",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"内功修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query("wlshw")<50 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"在江湖中的声望还不够，不配做我的弟子啊。");
                return;}
        else {
                command("say 好孩儿，你这么争气。。。");
                command("say 那为师这就收下你了，以后一定要勤加修炼，光大我全真派！！");
                command("say 驱逐鞑子，光复中华！！");
                command("recruit " + ob->query("id") );
                ob->add("wlshw",-50);
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
        add("apprentice_availavble", -1);
}


// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什-
么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真-
笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

string ask2()
{mapping fam;
        object me=this_player();
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "全真派" )
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        else
        {
        message_vision("开阳说道：“好吧，我就教你双手互搏吧。”\n",me);
        if (me->query_skill("yunu-jianfa",1)<200 
         || me->query_skill("quanzhen-jian",1)<200)               
        { message_vision("$N练了半天，还是没练会。”\n",me);
               
        return "也许是你玉女剑法和全真剑法不够，静不下心来练吧。\n";}
        message_vision("$N练了半天，学会了左右互搏之技。\n",me);
        me->set("zuoyou-hubo",1);
        me->set("suxin",1);
        return "记住，不要用我教你的来作恶，不然我决不轻饶。\n";
        }
} 
