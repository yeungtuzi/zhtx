// /d/xizang/ice.h

#include <ansi.h>

int freezing(object ob);

int freezing(object ob)
{
        object ob1;
        int water, food, force, temp;

	if (!objectp(ob)) return 1;
        water = ob->query("water");
        food = ob->query("food");
        water -= (random(2)+ 1) * water / 10;
        food -= (random(2));
        ob->set("water", water);
        ob->set("food", food);
        force = ob->query("max_force");
        if (!objectp(ob1=present("leather", ob))) {
          message_vision(HIW"$N身上衣衫单薄,感到十分寒冷.\n", ob);
          if (force >= 300) {
            message_vision("$N连忙运功抵御寒气侵袭.\n", ob);
            temp = ob->query("force");
            temp -= 20;
            if (temp >=0 ) {
              message_vision("$N运功抵御寒气侵袭,感觉好多了.\n"NOR, ob);
            } else { 
              temp = 0;
              message_vision("$N内力不足,无法抵御寒气侵袭,冻得发抖.\n"NOR, ob);
              ob->add("kee",-20);
            }
            ob->set("force", temp);
            if( environment(ob) == this_object())
                call_out("freezing", random(10), ob);
            return 1;
          }
          message_vision("$N无法抵御寒气侵袭,冻得发抖.\n"NOR, ob);
          ob->add("kee",-10);
          if( environment(ob) == this_object())
                call_out("freezing", random(10), ob);
          return 1;
        }
        if (!ob1->query("equipped")) {
          message_vision("$N自言自语:天气这么冷,还不快把皮衣穿上!\n", ob);
          ob->add("kee",-15);
        } else {
          message_vision(HIW"$N裹在暖和的皮衣里,仍然觉得有些寒冷.\n"NOR, ob);
        }
        if( environment(ob) == this_object())
                call_out("freezing", random(10), ob);
        return 1;
}
