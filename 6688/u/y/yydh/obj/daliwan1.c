#include <ansi.h>                                                                                                          
                                                                                                                           
inherit ITEM;                                                                                                              
                                                                                                                           
int do_eat(string);                                                                                                        
void init();                                                                                                               
                                                                                                                           
void init()                                                                                                                
{                                                                                                                          
        add_action("do_eat", "eat");                                                                                       
}                                                                                                                          
                                                                                                                           
void create()                                                                                                              
{                                                                                                                          
        set_name(HIG "御用大力丸" NOR, ({"dali wan", "wan"}));                                                             
        set_weight(20);                                                                                                    
        if (clonep())                                                                                                      
                set_default_object(__FILE__);                                                                              
        else {                                                                                                             
                set("unit", "枚");                                                                                         
                set("long",                                                                                                
"本品根据古代宫廷秘方，选用青藏高原天然、无污染的纯正药材，\n                                                              
 运用现代高科技工艺精制而成的最新一代补肾良药。\n                                                                          
它组方独特，药效强劲，无任何毒副作用，无激素，\n                                                                           
对阳痿、早泄、性功能衰退有特殊的改善作用。\n");                                                                            
                set("value", 100000);                                                                                      
        }                                                                                                                  
                                                                                                                           
        setup();                                                                                                           
}                                                                                                                          
                                                                                                                           
int do_eat(string arg)                                                                                                     
{                                                                                                                          
        object me = this_player();                                                                                         
                                                                                                                           
        if (!id(arg))                                                                                                      
                return notify_fail("你要吃什么？\n");                                                                      
      if (random(20)>6)       { me->add("combat_exp",random(11)*10000);                                                               
           me->add("potential",random(11)*1000);                                                                                      
        me->add("faith",random(11)*10);                                                                                               
                                                                                                                           
        message_vision(HIC                                                                                                 
 "$N吃下一枚大力丸，只觉得精神健旺，通体舒泰，身上不适之敢一扫而光! \n"NOR,me);                                            
         message("system",                                                                                                 
    HIM "\n【闲聊】大力丸(Dali wan)：听说"+me->name()+"服用的《东方不败》牌大力丸效果不错哦！\n" NOR, users()  );         }
else                                                                                                                       
    { me->add("combat_exp",-100);                                                                                          
        me->add("potential",-100);                                                                                         
        me->add("faith",-5);                                                                                               
        me -> unconcious();                                                                                                
message_vision(HIC                                                                                                         
 "$N吃下一枚大力丸，只觉得精神健旺，通体舒泰，身上不适之敢一扫而光! \n"NOR,me);                                            
         message("system",                                                                                                 
    HIM "\n【闲聊】大力丸(Dali wan)：听说"+me->name()+"服用了一颗假冒伪劣的《东方不败》牌大力丸，\n                        
              望大家提高警惕！\n" NOR, users()  );     }                                                                   
                                                                                                                           
        destruct(this_object());                                                                                           
        return 1;                                                                                                          
}                                                                                                                          
