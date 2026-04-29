// zhang.c 张三丰
#include <ansi.h>
inherit "/u/z/zephyr/revengenpc_new.c";  
inherit "/std/char/qlist.c";
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";
string ask_sword();
void heal();
void create()
{
        set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
        set("nickname", HIR "邋遢真人" NOR);
        set("long",
                "他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
                "身穿一件污秽的灰色道袍，不修边幅。\n"
                "身材高大，年满百岁，满脸红光，须眉皆白。\n");
        set("title",RED "武当派" NOR + GRN "开山" NOR+ RED "祖师" NOR);
        set("gender", "男性");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("cor", 50);
        set("no_get",1);
        set("max_kee", 5000);
        set("max_gin", 3000);
        set("max_sen", 300);
        set("atman", 300);
        set("max_atman", 300);
        set("mana", 300);
        set("max_mana", 300);
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 100);
          set("combat_exp", 5000000);
        set("score", 500000);
        set("inquiry", ([
              "拨云瞻日": (:ask_sword:),
        ]) );

		set("count",1);
        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function , "recover" :),
                (: exert_function , "refresh" :),
                (: exert_function , "regenerate" :),                
        }));

        set_skill("force", 220);
        set_skill("taiji-shengong", 250);
        set_skill("move", 200);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 200);
        set_skill("cuff", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 250);
        set_skill("literate", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("move", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 1, "开山祖师");
        set("class", "taoist");

        setup();                    
        set_temp("apply/armor_vs_force",300);
        set_temp("apply/armor",300);
        carry_object("/d/wudang/obj/zhenwu")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}


void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name") != "武当派")
        {
                command("say 我只收本门弟子，"+ RANK_D->query_respect(ob) + "可先拜谷虚。");
                return;
        }
        if ((int)ob->query_skill("taiji-shengong", 1) < 50) {
                command("say 我武当派乃内家武功，最重视内功心法。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在太极神功上多下点功夫？");
                return;
        }
        if ((int)ob->query("shen") <50000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，先学做人");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        if (ob->query_int() < 30) {
                command("say 我武当派武功全从道藏悟出。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性是半点也马虎不得");
                command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
                return;
        }
        if( ob->query("betrayer") )
        {
                command("say 你虽有向善之心，但是你已有武功跟我派不合，。\n");
                return;
        }
        command("chat 哈哈哈哈！！！！");
        command("chat 想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
        command("recruit " + ob->query("id"));
        this_player()->set("class", "taoist");
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",RED "武当派" NOR + GRN +"真人" NOR);
        else
                this_player()->set("title",RED "武当派" NOR + GRN +"女真人" NOR);
}

void init()
{

        object ob;
        mapping fam;

        ::init();
        add_action("give_quest","quest");
        ob = this_player();
        if ( (int)ob->query("shen") <=2000 && ((fam = ob->query("family")) && fam["master_id"] == "zhang sanfeng"))
        {
                command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
        }
}

string ask_sword()
{
        object me=this_player();

        if( me->query("family/family_name") != "武当派" )
                return "你不是本派弟子，问什么问！";
  
        if( me->query_skill("taiji-jian",1) < 220 )                   
                return "你的『太极剑』的修为太低，说了你也听不明白！";
                
        if( me->query("skill_mark/taiji-jian")  )
        {       
                return "我不是跟你解说过其中秘诀了么？怎么还问！";                      
        }       
        
        say(HIC"张三丰说道：当年武当派纵横天下，傲视群雄，靠就是这太极剑中的这招『拨云瞻日』。\n"NOR);
        say(HIC"张三丰说道：可惜后来树敌众多，终于被该死的流星雨给砍掉了。\n"NOR);
        say(HIC"张三丰说道：『拨云瞻日』，是太极剑发挥到及至时的凌厉招式，\n只有领会了阳阴相生水火并济的武学要旨，才能真正领会。\n"NOR);
        say(HIC"张三丰说道：好徒儿既然你的太极剑法已然日臻化境，为师这就传你这招『拨云瞻日』！\n"NOR);
        say(HIC"张三丰说道：切莫让流星雨看见了，不然咱们武当的日子又不好过了！\n"NOR);
        message_vision(HIG"$N经张三丰指点，不出半个时辰，这招『拨云瞻日』已经练得登峰造极！\n"NOR,me);
        tell_object(me,"你学会了太极剑中『拨云瞻日』这一招！\n");
        me->set("skill_mark/taiji-jian",1);
}                

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
                command("enforce 100");
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}

int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}


int accept_object(object ob, object obj)
{
        object obj1, reward;
        object me=this_object();   
         obj1=present("zhenwu sword",me);
         if(!obj1){
            return ::accept_object(ob,obj);
         }
        if ((obj->query("id")=="shu xin")&&(ob->query_temp("get-letter")))
         {   
          command("say 多谢英雄向告，老道无以回报，这把剑赠给英雄。\n");
          command("unwield sword");
          write("张真人把剑送给了你！\n");
          obj1->move(ob);
          deal_quest(ob,"真武剑");
            remove_call_out("destroying");
            call_out("destroying", 1, ob, obj);

         return 1;
          }
        if ((obj->query("id")=="zhenwudadi sword") && query("count"))
         {   
          command("say 哎呀！这这这.......\n");
          command("unwield zhenwu sword");
          command("wield zhenwudadi sword");
          command("say 真的是，真的是真武大帝神剑！\n");
          command("say 多谢英雄相助，找回我武当镇派之宝，老道我无以为报，也赠送英雄一把兵器吧！\n");
          reward=new("/obj/gf/secret/qixiujian");
		  reward->move(ob);
		  message_vision(CYN"张三丰从室内取出一柄古色古香的宝剑，郑重的交给了$N\n"NOR, this_player());
          command("say 七修剑虽乃绝世奇剑，但是却非凡物，老道有自知之明，从来没有使用过。\n");
          command("say 三天前此剑剑鞘不击自鸣，似乎在期待它的主人，今日便有此事，看来这位英雄乃有缘之人。\n");
          command("say 此剑就送与了英雄吧！\n");
		add("count",-1);
		 return 1;
          }

        return  ::accept_object(ob,obj); 
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

