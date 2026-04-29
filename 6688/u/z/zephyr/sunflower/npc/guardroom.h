//guardroom.h

void init()
{
        object hufa,me=this_player();
        if ( interactive(me) ) 
        {
            if ( ( random(100) >= 90 ) )
            {
				hufa=new("/u/z/zephyr/sunflower/npc/hufa");
				hufa->move(this_object());
				write(CYN"你不小心碰到了墙上一块圆圆的石头，只听"+CYN"吱嘎嘎一声响墙面转了过来，\n"NOR +
				YEL"从后面闪出一个少年，怀中抱着一个布包，里面冷气流动，仿佛是一柄神兵利器。\n"NOR + 
				CYN"少年弯腰鞠躬，冲你言道：主人说了，葵花圣宫，外人不得乱入。得罪了！\n"NOR,me);
				hufa->set_leader(me);
            }
        }
}
