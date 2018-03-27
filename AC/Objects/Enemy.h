#ifndef INCLUDED_AC_ENEMY_H
#define INCLUDED_AC_ENEMY_H

class ACEnemy
{
    private:
        LL_AL5::Image _V_enemy;
        float _V_max_speed;
    public:
        ACEnemy()
        {
            _V_enemy.set_anchor(0.5,0.5);
        }
        bool create_enemy(string enemy_path)
        {
            _V_enemy.set_path(enemy_path);
            return _V_enemy.load();
        }
        void set_max_speed(float new_max_speed)
        {
            _V_max_speed=new_max_speed;
        }
        LL_AL5::Type_pos get_pos_x()
        {
            return _V_enemy.get_pos_x();
        }
        LL_AL5::Type_pos get_pos_y()
        {
            return _V_enemy.get_pos_y();
        }
        void set_pos(LL_AL5::Type_pos new_pos_x,LL_AL5::Type_pos new_pos_y)
        {
            _V_enemy.set_pos(new_pos_x,new_pos_y);
        }
        void draw()
        {
            _V_enemy.draw();
        }
        void move(LL_AL5::Type_pos objective_x,LL_AL5::Type_pos objective_y)
        {
            if(_V_enemy.get_pos_x()<objective_x)
            {
                _V_enemy.set_pos_x(_V_enemy.get_pos_x()+_V_max_speed);
                _V_enemy.set_flag(ALLEGRO_FLIP_HORIZONTAL);
            }
            else
            {
                _V_enemy.set_pos_x(_V_enemy.get_pos_x()-_V_max_speed);
                _V_enemy.set_flag(0);
            }
            if(_V_enemy.get_pos_y()<objective_y)
                _V_enemy.set_pos_y(_V_enemy.get_pos_y()+_V_max_speed);
            else
                _V_enemy.set_pos_y(_V_enemy.get_pos_y()-_V_max_speed);
        }
        float get_size_x()
        {
            return _V_enemy.get_size_x();
        }
        float get_size_y()
        {
            return _V_enemy.get_size_y();
        }
};

#endif // INCLUDED_AC_ENEMY_H
