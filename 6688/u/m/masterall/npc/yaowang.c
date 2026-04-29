// yaow.c 
//by dwolf

#include <ansi.h>
inherit NPC;

string ask_for_per();
string ask_for_con();
int ask_yulu();
void do_opration(object ob, int stage);

string *make_msg = ({
        HIW"想做手术？好呀。--------哈哈。\n"NOR,       
        HIW"只见药王变戏法般的拿出一套工具，让你躺在一张石桌上，\n"NOR,
        YEL"手术开始了。\n"NOR,
        HIW"模模糊糊中，也不知道过了多久。。。。。。\n"NOR,
        HIM"只听的药王说道：行了。你才惊醒过来，发现自己的资质已经变了。\n"NOR,
});

void create()
{
        set_name(HIW"药王"NOR, ({ "yao wang", "wang" }));
        set("title", GRN"药王谷主"NOR);
        set("gender", "男性");
        set("long", "他就是医术高超的药王。看上去挺健康的。\n");
        set("age", 55+random(20));

        set("int", 30);

        set("kee", 1500);
        set("max_kee", 1500);
        set("gin", 1000);
        set("max_gin", 1000);
        set("shen_type", 5);

        set("combat_exp", 500000);
        set("attitude", "friendly");

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 60);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 50);   
        set("inquiry", ([
                "美容" : (: ask_for_per :),
                "per" : (: ask_for_per :),
                "健美" : (: ask_for_con :),
                "con" : (: ask_for_con :),
                "天仙玉露" : (: ask_yulu :),
        ]));                                                                                                                                                                                                                                                                                                                                                                                                                                            
     
        setup();
        add_money("gold", 1);
        carry_object("/d/huashan/obj/baishan")->wear();
}           

string ask_for_per()
{     
        object ob=this_player();
  
        if( ob->query("marks/fairy")==3)
                return "你不仅做过手术，而且已经恢复过经验，还来干什么？\n";
        if( ob->query("marks/手术") ) 
                return "老夫不能为你做两次手术。\n";
        if( ob->query("combat_exp") < 15000)
                 return "你体质太弱了，先去练练功夫吧\n";
        ob->start_busy(20);
        remove_call_out("do_opration");
        call_out("do_opration",1,ob,0);
        ob->add("combat_exp", -10000);
        ob->add("per", 1); 
        ob->set("marks/手术", 1);
        ob->set("marks/per",1);
        command("haha"); 
                return YEL"药王笑着看着你。\n"NOR;
}
   
string ask_for_con()
{       
        object ob=this_player();

        if( ob->query("marks/fairy")==3)
                return "你不仅做过手术，而且已经恢复过经验，还来干什么？\n";
        if( ob->query("marks/手术") ) 
                return "老夫不能为你做两次手术。\n";
        if( ob->query("combat_exp") < 15000)
                 return "你体质太弱了，先去练练功夫吧\n";
        ob->start_busy(20);
        remove_call_out("do_opration");
        call_out("do_opration",1,ob,0);
        ob->add("combat_exp", -15000);
        ob->add("con", 1); 
        ob->set("marks/手术",1);
        ob->set("marks/con",1);
                return YEL"药王笑着看着你。\n"NOR;
}

void do_opration(object ob, int stage)
{
        tell_object(ob, make_msg[stage]);
        if( ++stage < sizeof(make_msg) )
        {
        call_out("do_opration", 5, ob, stage );
                return;
        } 
        ob->start_busy(5);
}


int ask_yulu()
{       
        object obj1;
        command("hehe");
        tell_object(this_player(),HIC"药王对你说道：“天仙玉露乃是人间滋补的极品，极难炼制，需要以下几味药材：\n九转熊蛇丸，雪山红果，天香断玉膏，玉蜂浆。\n记得找来的时候要依次给我，否则下药的时候顺序不对就前功尽弃了！！”\n"NOR);

        this_player()->set_temp("ask-lu", 1);
        return 1;
}

int accept_object(object ob, object obj)
{
        object obj1;    
        object me=this_object();
        if (!(int)ob->query_temp("ask-lu"))
        return 0;
        if (obj->query("id")=="gui wan")
        {
         
         ob->set_temp("guiwan",1);
         destruct(obj);
         command("nod");
        }
        else if (obj->query("id")=="xueshan hongguo")
        {
         ob->set_temp("guo",1);
        destruct(obj);
           command("thumb");
         }
         
        else if (obj->query("id")=="tianxiang gao")
        {                       
         ob->set_temp("gao",1);
        destruct(obj);

           command("applaud");
        }
        else if (obj->query("id")=="yufeng jiang")
        {                           
         ob->set_temp("jiang",1);
        destruct(obj);

           command("nod2");
        }  
        
        if (ob->query_temp("ask-lu")&&                
            ob->query_temp("guiwan")&&
            ob->query_temp("guo")&&
            ob->query_temp("gao")&&
            ob->query_temp("jiang")
            )
        {       

                obj1=new("/d/qiankun/obj/nineflower.c");
                obj1->move(ob);
        tell_object(this_player(),HIG"药王将这几味药材依次放进一个小的器皿里，咕嘟咕嘟熬了半天，过了半饷，方始成药。\n"NOR);
        tell_object(this_player(),HIG"药王擦了擦额头的汗，笑嘻嘻的对你说道，“好了”，随即给你一支天仙玉露。\n"NOR);
                ob->delete_temp("ask-lu");
                ob->delete_temp("guiwan");
                ob->delete_temp("guo");
                ob->delete_temp("gao");
                ob->delete_temp("jiang");
                
         }      
       else 
        if(
            ob->query_temp("guiwan")||
            ob->query_temp("guo")||
            ob->query_temp("gao")||
            ob->query_temp("jiang")
            ) 
      
        return 1;
         
        else {command("sigh");
        return 0;  
             }

}
void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

