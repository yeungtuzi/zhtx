#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(HIW"雪蛤蟆"NOR,({"snowfrog","snow frog"}));
  set("long",
      "这是一只冰清玉洁的雪蛤蟆\n"
      "可以用来解（ｅａｔ）百毒！\n");
  set("food_remaining", 5);
  set("value",10000);
  set("unit","只");
}

int do_eat(string arg)
{
       if( !this_object()->id(arg) ) return 0;
                     
       set("value", 1);
       add("food_remaining", -1);
       if( !query("food_remaining") ) {
            message_vision("$N将剩下的" + name() + "吃得乾乾净净。\n", this_player());
            if( !this_object()->finish_eat() )
                    destruct(this_object());
       } else 
            message_vision("$N把雪蛤蟆用手捏碎一点后服了下去！\n",this_player());

        {
        int xiandan,bonze;
        xiandan = this_player()->query_condition("xiandan_drug");
        bonze = this_player()->query_condition("bonze_drug");
        this_player()->clear_condition();
        this_player()->apply_condition("xiandan_drug", xiandan);
        this_player()->apply_condition("bonze_drug", bonze);
        message_vision("$N的腹内＂隆隆＂作响！\n",this_player());
        }  
  
        return 1;
}
