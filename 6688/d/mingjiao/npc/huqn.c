/*
        银叶的秘密：
        1. 完成dayisi的秘密。
        2. 向谢逊打听yinye
        3，向hu qingniu打听yinye死因。
        3. 向金花打听yinye,同意追查死因。
        4. 向yang xiao打听其独门毒药。
        5。找 hu qingniu鉴定毒药
        6。和范遥对质，杀之。
        7。找金花报告，化解和胡青牛的冤仇。
        8。向hu qingniu报告。得到奖励。
*/

// saint.c
// written by tang
//1998.5.9

#include <ansi.h>

inherit NPC;
//inherit F_CONDITION;

void use_poison();
string ask_heal();
int ask_yinye();
string ask_for_reward(object ob);
void msg(object who,int stage);
string *msgs=({
HIY"胡青牛长叹一声，慨然说到：\n"NOR,
HIY"“当年银叶先生和夫人来此求医，我就发现他所中之毒甚为奇怪，\n",
"拒金花婆婆所言是一西域头陀所下之毒，可两人所中分量却相去、\n",
"甚远。我碍于自己毒誓，未能为其医治，但是他们所中之毒，似 \n",
"为我教内独有。我这里有一些当年我发现的他中的毒药，你拿去吧。”\n"NOR,
});
void create()
{
        set_name(HIY"胡青牛"NOR, ({ "hu qingniu","hu" }) );
        set("title",HIC"蝶谷医仙"NOR);
        set("nickname", HIR"见死不救"NOR);
        set("gender", "男性");
        set("age", 50);
        set("long", 
"胡青牛的怪脾气和他的医术同样的出名，他不愿意出手相救的人即使
倒毙在他面前他也无动于衷。他更有一个规矩就是：非明教弟子不医。
他不但精于医术，更是用毒解毒的大行家。\n");

        set("attitude", "peaceful");

        set("str", 100 + random(16));
        set("cps", 100 + random(16));
        set("int", 100 + random(16));
        set("cor", 100 + random(16));
        set("con", 100 + random(16));
        set("spi", 100 + random(16));
        set("per", 10 + random(16));
        set("kar", 100 + random(16));
                                        
        set("kee",2000);
        set("max_kee", 2000);
        set("gin",1000);
        set("max_gin", 1000);
        set("sen",1000);
        set("max_sen", 1000);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 100);
        set("max_mana", 100);

        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 50);

        set("combat_exp", 5000000);
        set("shen_type",-1);

        set_skill("force", 200);
        set_skill("sword", 200);
        set_skill("throwing", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);                            
        set_skill("move", 200);
        set_skill("strike",200);
        set_skill("dugong", 200);
        set_skill("literate", 200);

        set_skill("tangmen-xinfa", 200);
        set_skill("tangshi-jian", 200);
        set_skill("mantian-huayu", 200);
        set_skill("taxue-wuhen", 200);
        set_skill("tangmen-duzhang",200);

        map_skill("dodge", "taxue-wuhen");
        map_skill("move", "taxue-wuhen");
        map_skill("force", "tangmen-xinfa");
        map_skill("sword", "tangshi-jian");
        map_skill("parry", "tangshi-jian");   
        map_skill("strike", "tangmen-duzhang");
        map_skill("throwing", "mantian-huayu");

        prepare_skill("strike","tangmen-duzhang");

        set_temp("apply/defense", 100);

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                "胡青牛左手一扬，从袖中发出一阵青烟。\n",
                (: use_poison :),              
        }) );

        set("inquiry", ([
                "疗伤": 
                        (: ask_heal :),
                "银叶先生": 
                        (: ask_yinye :),
                "奖励": (: ask_for_reward :),

        ]) );   

        setup();

//        carry_object("/d/tangmen/obj/huixuanbiao")->wield();
//        carry_object("/d/shaolin/obj/cloth")->wear();
}




string ask_for_reward(object ob)
{
        object yao,jing;
        int     j;

        //  最多完成三次
        ob = this_player();
        if( (j=(int)(ob->query("marks/银叶_credit")) < 3) && (ob->query("marks/银叶_success")))
        {
                //第一次给奖励
                ob->delete("marks/银叶_success");
                ob->add("marks/银叶_credit",1);
                if( (j=(int)(ob->query("marks/银叶_credit"))) ==1 )
                {
                        tell_object(ob,"你由于成功地解决了这个悬案而提高了自己的武林声望！\n");
                        ob->add("wlshw",5);
                }
                else if( (j=(int)(ob->query("marks/银叶_credit"))) ==3 )
                {
                        tell_object(ob,"胡青牛感激地说："+RANK_D->query_respect(ob)+"解开了老朽多年的一桩心事，大恩不敢言谢，\n
                                我手头还有多年炼制的一点药材，略表寸心。\n");
                        yao = new(__DIR__"obj/jiuzhuandan");
                        yao->move(ob);
                }
                else if( (j=(int)(ob->query("marks/银叶_credit"))) ==2 )
                {
                        if( present("wang nangu",environment(this_object())) )
                        {
                                tell_object(ob,"\n\n王难姑感激地说：老太婆这里还有一本毒经，是我多年心血，就送于" + RANK_D->query_respect(ob) + "，万望笑纳。\n");
                                jing = new(__DIR__"obj/dujing");
                                jing->move(ob);
                        }
                }
                ob->add("combat_exp",random(1000));
        }
}

string ask_heal()
{
        string *conditions=({}),*list,arg;
        int i;
        object drug,who;

        who = this_player();

        if( who->query("family/family_name") != "明教")
                return "非我明教弟子，不医不医！\n";

        if( this_object()->is_busy() )
                return "我正在给人疗伤，" + RANK_D->query_respect(who) + "稍安勿躁。";

        list = get_dir("/daemon/condition/");

        i = sizeof(list);
        while( i-- )
        {
                arg = list[i];
                if( arg[strlen(arg)-8..strlen(arg)-3] == "poison" )
                {
                        conditions += ({arg[0..strlen(arg)-3]});
                        if( who->query_condition(arg[0..strlen(arg)-3]) )
                                who->set_temp("marks/有毒",1);
                }
        }

        if( !who->query_temp("marks/有毒") )
                return "你没有中毒啊。若是区区跌打损伤，似乎还不值得老夫出手。\n";        
        message_vision(
                HIG "$N坐了下来运起内功给$n解毒....\n\n"NOR,this_object(),who );
        message_vision(HIG"过了不久，$N额头上冒出豆大的汗珠，从$n手指尖滴出一缕黑血，

黑血渐渐由黑转红...\n\n"NOR,this_object(),who);

        this_object()->start_busy(10);
        who->start_busy(2);

        i = sizeof(conditions);
        while(i--) 
        {
                if( who->query_condition(conditions[i]) > 0 )
                        who->apply_condition(conditions[i],0);
        }
        
        who->delete_temp("marks/有毒");
        return "好啦，你体内的毒已经解啦\n";
}

int ask_yinye()
{
        object who;
        who=this_player();
        if( !who->query("marks/银叶_1") )
        {
                command("say 你问这个干什么？\n");      
                return 0;
        }
        who->delete("marks/银叶_1");
        who->set("marks/银叶_2",1 );
        call_out("msg",1,who);
        return 1;
}


void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( random(query("combat_exp")) > (int)ob->query("combat_exp")/2 )
        {
                tell_object(ob, "你觉得脸上一痒，似乎有什麽东西，伸手一摸却什麽也没有。\n");
                switch(random(3))
                {
                        case 0:
                                ob->apply_condition("tm_poison", random(20)+ob->query_condition("tm_poison"));    
                                break;
                        case 1:
                                ob->apply_condition("rose_poison", random(20)+ob->query_condition("rose_poison"));    
                                break;
                        case 2:
                                ob->apply_condition("ninemoonpoison", random(20)+ob->query_condition("ninemoonpoison"));    
                                break;
                }
        }
        return ;
}

void msg(object who,int stage)
{       
         object du;
         
         who=this_player();
         message_vision(msgs[stage],who);
         if( ++stage < sizeof(msgs) ) 
         {
          call_out( "msg", 3, who, stage );
         }
         du = new(__DIR__"obj/xyduyao");
         if( objectp(du) )
                du->move(who);
}

