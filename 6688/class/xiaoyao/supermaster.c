// master.c

#include <ansi.h>

inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;
inherit F_QUEST;
inherit "/feature/challenge";

void do_recruit_xiaoyao(object who);
int ask_steps();

void create()
{
        set_name("无崖子", ({ "wuya zi", "zi", "wuya" }) );
        set("gender", "男性");
        set("age", 93);
        set("attitude", "peaceful");
        set("long", @LONG
他脸如冠玉，须长三尺，容貌极是俊雅。可惜双腿已然残废，困在这深谷之中。
LONG);

        set("int", 30);
        set("spi", 30);
        set("con", 30);
        set("cps", 30);
        set("per", 30);
        set("cor", 30);
        set("kar", 30);

        set("force", 6000);
        set("max_force", 4000);
        set("force_factor", 150);
        set("mana", 800);
        set("max_mana", 800);
        set("atman", 800);
        set("max_atman", 800);
     
        set("combat_exp", 4500000);
        set("shen", 11336);

        set("inquiry", ([
                "凌波微步" : (: ask_steps :),
        ]) );

        set_skill("force", 220);
        set_skill("dodge", 180);
        set_skill("literate", 200);
        set_skill("parry", 200);
        set_skill("throwing", 150);
        set_skill("perception",180);
        set_skill("hand", 200);
        set_skill("finger", 220);
        set_skill("strike", 200);
        set_skill("sword", 150);
        set_skill("axe", 150);
        set_skill("hammer", 150);
        set_skill("unarmed", 150);
        set_skill("drawing", 200);
        set_skill("qi", 200);
        set_skill("qimen-bagua", 200);
        set_skill("staff", 150);
        set_skill("whip", 150);
        set_skill("music", 200);
        set_skill("move", 180);
        set_skill("flattering", 180);
        set_skill("tianshan-zhang", 180);
        set_skill("staff", 200);
        
        set_skill("beiming-shengong", 200);
        set_skill("bahuang-gong", 180);
        set_skill("xiaowuxiang-gong", 180);
        set_skill("lingboweibu", 180);
        set_skill("zhemei-shou", 200);
        set_skill("liuyang-zhang", 200);

        map_skill("force", "beiming-shengong");
        map_skill("dodge", "lingboweibu");
        map_skill("hand", "zhemei-shou");
        map_skill("strike", "liuyang-zhang");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("hand", "zhemei-shou");
        prepare_skill("strike", "liuyang-zhang");

        create_family("逍遥派", 2, "掌门人");
        set("family/create_time",6);
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
                (: exert_function,"recover":)
        }));
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"ring");
}

void init()
{
        add_action("do_answer", "answer");
        add_action("give_quest", "quest");
        if( interactive(this_player()) && !is_fighting()){
                remove_call_out("greeting");
                call_out("greeting", 1, this_player());
        }
        ::init();
}

int accept_learn(object me,string skill)
{
        if( skill == "beiming-shengong" && me->query_skill("beiming-shengong", 1) > 180 ){
                return notify_fail("逍遥子对你说：“你不宜再练北冥神功，否则会走火入魔。”\n");
        }
/*
        if( skill == "zhemei-shou" && me->query("birthday") % 2 == 0 ){
                return notify_fail("逍遥子对你说：“你还是专攻天山六阳掌吧！”\n");
        }       
        if( skill == "liuyang-zhang" && me->query("birthday") % 2 == 1 ){
                return notify_fail("逍遥子对你说：“你还是专攻天山折梅手吧！”\n");
        }  
*/     
        return ::accept_learn(me, skill);
}

void greeting(object ob)
{
        if( ob->query("mark/ding_chushi") == 6 ){
                ob->delete_condition("fushi-du");
                command("say 你终于醒来啦！你从崖顶掉下来，要不是幸好杨兄和独孤兄在场，早就粉身碎骨了。对了，你身上有化功大法的功力，该当是丁春秋的弟子，他为何又要害你？(answer)");
                return;
        }
        return;
}

int do_answer()
{
        object ob;

        ob = this_player();

        if( ob->query("mark/ding_chushi") != 6
        || ob->query("family/title") != "弃徒"
        || ob->query("family/master_id"))       return 0;
        message_vision("$N说道：“话还得从夺得"+ob->query("gender") == "女性"?"大师姐":"大师兄"+"说起，那日我打败摘星子，丁春秋便开始对我起了戒心。。。。。。”\n\n", ob);
        message_vision("$N于是把如何丁春秋起疑，如何从出云子口中得知丁是逍遥派叛徒，如何在丁的卧室中见到送给苏星河的书信进一步得到确认，又如何行踪泄露，如何逃出星宿海，如何被丁春秋追杀，最后被丁春秋推下悬崖，原原本本地对老者说了。\n", ob); 
        command("sigh");
        message_vision("无名老者听了$N的诉说，深深叹了口气，都怪我当初有眼无珠，错收了徒弟，以至留下了丁春秋这个祸患！\n", ob);
        EMOTE_D->do_emote(ob, "ah");
        message_vision("$N指着无名老者道：“你...你就是信上所说的无崖子？你真的没有死？”\n", ob);
        command("say 正是，老夫就是逍遥派的掌门人无崖子，当年虽从这崖顶摔下来，但有杨兄和独孤兄在，你想若是死了，又怎么对得起这两位老兄呢？\n");
        command("say 我看你虽从小跟着丁春秋，但本心不坏，你不如入我门下，从此喜心革面，重新做人，将来未使不能有一番作为？\n");
        message_vision("无名老者想收$N做徒弟", ob);
        ob->set("mark/ding_chushi", 7);
       ob->set("family/family_name", "逍遥派");
        return 1;
}
        
int accept_object(object who, object ob)
{
        if( ob->id("tianshan letter") && who->query("mark/tong_chushi") == 2
        && who->query("family/family_name") == "灵鹫宫"){
                message_vision("无名老者接过信来看了一遍。\n", who);
                command("say 很好，看来你是师姐的得意弟子了，我就是无崖子。");
                command("say 我这就教你凌波微步，愿你学成之后，替本门铲除丁春秋这个叛徒。");
                who->delete("mark/tong_chushi");
                who->set("family/family_name", "逍遥派");
                do_recruit_xiaoyao(who);
                who->set("mark/童徒", 1);
                return 1;
        }
        
        return ::accept_object(who, ob);
}

void do_recruit_xiaoyao(object who)
{
        who->set("family/family_name", "逍遥派");
        who->set("family/master_name", "无崖子");
        who->set("family/generation", 3);
        who->set("family/title", "弟子");
        who->set("family/master_id", "wuya zi");
        who->set("family/enter_time", time());
        who->set("family/privs", 0);
        who->set("title", HIC"逍遥"+HIG"派"+NOR"第三代弟子");
        tell_object(who, "恭喜你成为逍遥派第三代弟子。\n");

        return;
}

void attempt_apprentice(object ob)
{
        if( ob->query("mark/su_chushi") == 4
        && ob->query("family/family_name") == "逍遥派"){
                ob->delete("mark/su_chushi");
                command("say 很好，看来你是星河的高徒了，我就是无崖子。");
                command("say 你能跟我说说是怎么破解了珍珑棋局吗？");
                message_vision("$N于是把破解的前后经过详细说了一遍，无崖子听得连连点头。\n", ob);
                command("say 你梦中得高人指点，乃是天意，看来我们报仇的机会又多了几成。");
                command("say 我就收你为徒，愿你学成之后，杀了丁春秋这逆贼，为本门清理门户。");
                do_recruit_xiaoyao(ob);
                ob->set("mark/苏徒", 1);
                return;
        }
        if( ob->query("mark/ding_chushi") == 7 ){
                ob->delete("mark/ding_chushi");
                command("say 好徒儿，本派武学博大精深，丁春秋不过学了点皮毛，居然就想暗算为师！\n");
                command("say 要不是为师当年一念之仁，也不至于落到如此下场！");
                command("say 你日后只要刻苦用功，必可手刃丁春秋这逆贼，为本门清理门户。");
                ob->add("betrayer", -1);
                ob->set("faith", 50);
                do_recruit_xiaoyao(ob);
                ob->set("mark/丁徒", 1);
                return;
        }
        return;
}

int ask_steps()
{
        object ob, pic;

        ob = this_player();

        if( ob->query("family/family_name") != "逍遥派"
        && ob->query("family/master_name") != "无崖子" )
                return 1;

        if( ob->query_skill("lingboweibu", 1) < 180 ){
                command("sigh");
                command("say 双腿不行了，要不然。。。\n");
                return 1;
        }

        if( ob->query_temp("finding_qiushui") )
                return notify_fail("我不是和你说了吗？\n");
        
        command("say 我双腿不行了，要不然还可以多教你一些。");
        message_vision("无崖子从怀里拿出一个画卷来，对$N说道：“你去持此画卷去找画中之人，她看在我的面子上也许会指点你一二。”\n", ob);
        message_vision("无崖子给$N一幅画卷。\n", ob);
        pic = new(__DIR__"picture");
        pic->set("mark", "qiushui");
        pic->move(ob);
        ob->set_temp("finding_qiushui", 1);
        return 1;
}

