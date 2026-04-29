#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
string ask2();

void create()
{
        set_name("小雨", ({ "xiao yu", "rain" }));
        set("nickname", HIB"夜雨"+HIG"潇湘"NOR);
        set("long", 
"她就是传说中的古墓第一高手，已然归隐江湖，后来好像做了神仙，具体细节\n"
"去问一个叫懒猪的巫师吧，呵呵，别误会哦，它可一点都不懒，有问题找它就\n"
"好了。\n");

        set("gender", "女性");
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
        set_skill("xianyun", 200);
        set_skill("xiantian-gong", 250);
        set_skill("fx-step",200);
        set_skill("tonggui-jian", 250);
        set_skill("quanzhen-jian", 250);
        set_skill("xuantie-sword", 220);
        set_skill("jiuyin-shengong", 220);
        set_skill("iron-cloth", 220);
        set_skill("taoism", 250);
        set_skill("yunu-jianfa", 200);
        set_skill("anran-zhang", 200);
        set_skill("array", 200);
        set_skill("cuff", 200);
        set_skill("tiangang-beidou", 200);
        set_skill("yangxin-quan", 200);
        set_skill("yunu-xinfa", 200);
        set_skill("cuff", 200);
        set_skill("cuff", 200);





        map_skill("force", "xiantian-gong");
        map_skill("array", "tiangang-beidou");
        map_skill("sword", "xuantie-sword");
        map_skill("dodge", "fx-step");
        map_skill("move", "xianyun");
        map_skill("parry", "quanzhen-jian");
        map_skill("iron-cloth", "jiuyin-shengong");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger", "yiyang-zhi");

        create_family("古墓派", 2, "飞天圣女");
        set("title",HIG "古墓派" NOR + HIR "飞天"+HIW"圣女" NOR);
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

//    carry_object("/d/qiankun/obj/weapon/tiandunshenjian")->wield();

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
        if( !ob->query("mpweapon_got") ){
                command("say 本派神兵在江湖上已经失落多年，你如果能找到它我就收你为徒。");
                return;}
        if( (int)ob->query("combat_exp") < 12800000 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"江湖经验还不够丰富，还需回去多点历练，否则不配做我的弟子。");
                return;}

        if( (int)ob->query_skill("sword",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"剑术修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query_skill("force",1) < 250 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"内功修为还不够，还需回去勤加修炼，否则不配做我的弟子。");
                return;}
        if( (int)ob->query("wlshw")<50 ){
                command("say 这位" + RANK_D->query_respect(ob)
                  +"在江湖中的声望还不够，不配做我的弟子啊。");
                return;}
        else {
                command("say 你历经千辛万苦能来到侠客岛，不愧为本派的后起之秀，古墓派的将来就交给你了。");
                command("say 终南山的全真教与本派大有渊源，今后一定要互亲互近。");
                command("say 古墓派虽然一向很少在江湖走动，但如果让我听到你为非作歹，一定不会饶过你的！");
                command("recruit " + ob->query("id") );
                ob->add("wlshw",-50);
                if(ob->query("gender")== "女性") ob->set("title",HIG"古墓派"+HIR"飘然"+HIW"圣女"NOR);
                if(ob->query("gender")== "男性") ob->set("title",HIG"古墓派"+HIR"仙逸"+HIW"圣使"NOR);
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
           //     ob->set("class", "taoist");
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
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
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

